//
//  SettingsView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/5/25.
//


import SwiftUI
import SwiftData

struct SettingsView: View {
    @Environment(\.modelContext) private var modelContext
    @Query private var users: [User]
    
    @State private var userName: String = ""
    @State private var themePreference: ThemePreference = .system
    @State private var showDeleteConfirmation = false
    
    var body: some View {
        NavigationStack {
            Form {
                // MARK: - User Preferences Section
                Section(header: Text("User Preferences")) {
                    // Name input field
                    TextField("Your Name", text: $userName)
                        .onAppear {
                            if let user = users.first {
                                userName = user.name
                                themePreference = user.themePreference
                            }
                        }
                        .onChange(of: userName) { oldValue, newValue in
                            updateUserSettings()
                        }
                    
                    // Theme selection
                    Picker("App Theme", selection: $themePreference) {
                        Text("Light").tag(ThemePreference.light)
                        Text("Dark").tag(ThemePreference.dark)
                        Text("System").tag(ThemePreference.system)
                    }
                    .pickerStyle(SegmentedPickerStyle())
                    .onChange(of: themePreference) { oldValue, newValue in
                        updateUserSettings()
                        ThemeManager.applyTheme(themePreference)
                    }
                }
                
                // MARK: - Data Management Section
                Section(header: Text("Data Management")) {
                    Button(role: .destructive, action: {
                        showDeleteConfirmation = true
                    }) {
                        HStack {
                            Image(systemName: "trash")
                            Text("Reset All Data")
                        }
                    }
                }
                
                // MARK: - App Information Section
                Section(header: Text("About")) {
                    HStack {
                        Text("Version")
                        Spacer()
                        Text("1.0.0")
                            .foregroundColor(.secondary)
                    }
                }
            }
            .navigationTitle("Settings")
            .confirmationDialog(
                "Reset All Data",
                isPresented: $showDeleteConfirmation,
                titleVisibility: .visible
            ) {
                Button("Delete", role: .destructive, action: deleteAllData)
                Button("Cancel", role: .cancel) { }
            } message: {
                Text("This will delete all exercises, workouts, and history. This action cannot be undone.")
            }
        }
    }
    
    // MARK: - Helper Methods
    
    /// Updates the user settings in the database
    private func updateUserSettings() {
        if let user = users.first {
            // Update existing user
            user.name = userName
            user.themePreference = themePreference
        } else {
            // Create new user if none exists
            let newUser = User(name: userName, themePreference: themePreference)
            modelContext.insert(newUser)
        }
        try? modelContext.save()
    }
    
    /// Deletes all app data except the user profile
    private func deleteAllData() {
        // Delete all workouts
        let workoutFetchDescriptor = FetchDescriptor<Workout>()
        if let workouts = try? modelContext.fetch(workoutFetchDescriptor) {
            for workout in workouts {
                modelContext.delete(workout)
            }
        }
        
        // Delete all exercise sets
        let setFetchDescriptor = FetchDescriptor<ExerciseSet>()
        if let sets = try? modelContext.fetch(setFetchDescriptor) {
            for set in sets {
                modelContext.delete(set)
            }
        }
        
        // Delete all exercises
        let exerciseFetchDescriptor = FetchDescriptor<Exercise>()
        if let exercises = try? modelContext.fetch(exerciseFetchDescriptor) {
            for exercise in exercises {
                modelContext.delete(exercise)
            }
        }
        
        // Keep the user but reset name if needed
        if let user = users.first, user.name.isEmpty {
            user.name = "User"
            try? modelContext.save()
            userName = user.name
        }
        
        try? modelContext.save()
    }
}