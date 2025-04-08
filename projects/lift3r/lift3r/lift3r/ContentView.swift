//
//  ContentView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/5/25.
//


import SwiftUI
import SwiftData

// MARK: - Main Content View with Tab Navigation
struct ContentView: View {
    @Environment(\.modelContext) private var modelContext
    @Query private var users: [User]
    
    @State private var selectedTab = 0
    
    var body: some View {
        TabView(selection: $selectedTab) {
            // Home/Workout Tab
            HomeView()
                .tabItem {
                    Label("Workout", systemImage: "dumbbell")
                }
                .tag(0)
            
            // Exercises Tab
            ExercisesView()
                .tabItem {
                    Label("Exercises", systemImage: "list.bullet")
                }
                .tag(1)
            
            // History Tab
            HistoryView()
                .tabItem {
                    Label("History", systemImage: "clock")
                }
                .tag(2)
            
            // Settings Tab
            SettingsView()
                .tabItem {
                    Label("Settings", systemImage: "gear")
                }
                .tag(3)
        }
        .onAppear {
            // Set the tab bar appearance for iOS 18
            let appearance = UITabBarAppearance()
            appearance.configureWithDefaultBackground()
            UITabBar.appearance().standardAppearance = appearance
            UITabBar.appearance().scrollEdgeAppearance = appearance
            
            // If running on iOS 18+, use the newer API
            if #available(iOS 18.0, *) {
                UITabBar.appearance().standardAppearance = appearance
                UITabBar.appearance().scrollEdgeAppearance = appearance
            }
        }
    }
}

// MARK: - Preview Provider
#Preview {
    ContentView()
        .modelContainer(for: [User.self, Exercise.self, ExerciseSet.self, Workout.self], inMemory: true)
        .onAppear {
            // Create sample data for previews
            let previewContext = ModelContext(ModelContainer.lift3rContainer)
            
            // Sample user
            let user = User(name: "Preview User", themePreference: .system)
            previewContext.insert(user)
            
            // Sample exercise
            let exercise = Exercise(
                name: "Bench Press",
                equipmentType: .freeweight,
                targetMuscle: "Chest",
                manufacturer: "Rogue"
            )
            previewContext.insert(exercise)
            
            // Sample workout
            let workout = Workout(startTime: Date().addingTimeInterval(-3600))
            workout.endTime = Date()
            workout.exercises = [exercise]
            
            let set = ExerciseSet(reps: 10, weight: 100.0, rpe: 8)
            set.exercise = exercise
            set.workout = workout
            
            if workout.sets == nil {
                workout.sets = []
            }
            workout.sets?.append(set)
            
            if exercise.sets == nil {
                exercise.sets = []
            }
            exercise.sets?.append(set)
            
            previewContext.insert(workout)
            previewContext.insert(set)
            
            try? previewContext.save()
        }
}
