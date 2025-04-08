import SwiftUI
import SwiftData
import Charts

// MARK: - Main Exercises List View
struct ExercisesView: View {
    @Environment(\.modelContext) private var modelContext
    @Query private var exercises: [Exercise]
    
    @State private var showingAddExercise = false
    @State private var searchText = ""
    @State private var showDeleteAlert = false
    @State private var exerciseToDelete: Exercise?
    @State private var showUndoAlert = false
    @State private var recentlyDeletedExercise: Exercise?
    
    // Filter exercises based on search text
    var filteredExercises: [Exercise] {
        if searchText.isEmpty {
            return exercises
        } else {
            return exercises.filter { exercise in
                exercise.fullName.localizedCaseInsensitiveContains(searchText) ||
                exercise.targetMuscle.localizedCaseInsensitiveContains(searchText)
            }
        }
    }
    
    var body: some View {
        NavigationStack {
            List {
                ForEach(filteredExercises) { exercise in
                    NavigationLink(destination: ExerciseDetailView(exercise: exercise)) {
                        VStack(alignment: .leading) {
                            Text(exercise.fullName)
                                .font(.headline)
                            
                            Text("Target: \(exercise.targetMuscle)")
                                .font(.subheadline)
                                .foregroundColor(.secondary)
                        }
                    }
                }
                .onDelete(perform: deleteExercises)
            }
            .navigationTitle("Exercises")
            .searchable(text: $searchText, prompt: "Search exercises")
            .toolbar {
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button(action: {
                        showingAddExercise = true
                    }) {
                        Image(systemName: "plus")
                    }
                }
                
                ToolbarItem(placement: .navigationBarLeading) {
                    EditButton()
                }
            }
            .sheet(isPresented: $showingAddExercise) {
                NavigationStack {
                    ExerciseFormView(isPresented: $showingAddExercise)
                        .navigationTitle("Add Exercise")
                }
            }
            .alert("Delete Exercise", isPresented: $showDeleteAlert) {
                Button("Cancel", role: .cancel) {}
                Button("Delete", role: .destructive) {
                    if let exercise = exerciseToDelete {
                        // Store for potential undo
                        storeDeletedExercise(exercise)
                        
                        // Delete from database
                        modelContext.delete(exercise)
                        try? modelContext.save()
                        
                        // Show undo option
                        showUndoAlert = true
                    }
                }
            } message: {
                Text("Are you sure you want to delete this exercise? This will not affect past workouts.")
            }
            .alert("Exercise Deleted", isPresented: $showUndoAlert) {
                Button("Undo", role: .cancel) {
                    undoDelete()
                }
                Button("OK", role: .none) {}
            } message: {
                Text("Exercise has been deleted.")
            }
        }
    }
    
    // MARK: - Helper Methods
    
    /// Handles deletion of exercises
    private func deleteExercises(at offsets: IndexSet) {
        if let index = offsets.first {
            let exercise = filteredExercises[index]
            exerciseToDelete = exercise
            showDeleteAlert = true
        }
    }
    
    /// Stores deleted exercise for potential undo
    private func storeDeletedExercise(_ exercise: Exercise) {
        // Create a copy of the exercise properties
        let exerciseCopy = Exercise(
            name: exercise.name,
            equipmentType: exercise.equipmentType,
            targetMuscle: exercise.targetMuscle,
            manufacturer: exercise.manufacturer
        )
        recentlyDeletedExercise = exerciseCopy
    }
    
    /// Restores the recently deleted exercise
    private func undoDelete() {
        if let exerciseCopy = recentlyDeletedExercise {
            modelContext.insert(exerciseCopy)
            try? modelContext.save()
            recentlyDeletedExercise = nil
        }
    }
}

// MARK: - Exercise Form View (Add/Edit)
struct ExerciseFormView: View {
    @Environment(\.modelContext) private var modelContext
    @Binding var isPresented: Bool
    
    var exerciseToEdit: Exercise?
    
    @State private var name = ""
    @State private var equipmentType = EquipmentType.freeweight
    @State private var targetMuscle = ""
    @State private var manufacturer = ""
    
    @State private var showValidationAlert = false
    @State private var validationMessage = ""
    
    var isEditing: Bool {
        exerciseToEdit != nil
    }
    
    var body: some View {
        Form {
            Section(header: Text("Exercise Details")) {
                TextField("Name", text: $name)
                
                Picker("Equipment Type", selection: $equipmentType) {
                    Text("Cable").tag(EquipmentType.cable)
                    Text("Machine").tag(EquipmentType.machine)
                    Text("Freeweight").tag(EquipmentType.freeweight)
                }
                .pickerStyle(DefaultPickerStyle())
                
                TextField("Target Muscle", text: $targetMuscle)
                TextField("Manufacturer", text: $manufacturer)
            }
            
            Section {
                Button(isEditing ? "Update Exercise" : "Add Exercise") {
                    if validateForm() {
                        saveExercise()
                        isPresented = false
                    } else {
                        showValidationAlert = true
                    }
                }
                .frame(maxWidth: .infinity, alignment: .center)
                .foregroundColor(.blue)
            }
        }
        .onAppear {
            if let exercise = exerciseToEdit {
                name = exercise.name
                equipmentType = exercise.equipmentType
                targetMuscle = exercise.targetMuscle
                manufacturer = exercise.manufacturer
            }
        }
        .alert("Invalid Form", isPresented: $showValidationAlert) {
            Button("OK", role: .cancel) {}
        } message: {
            Text(validationMessage)
        }
    }
    
    /// Validates form input
    private func validateForm() -> Bool {
        // Basic validation for required fields
        if name.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty {
            validationMessage = "Exercise name cannot be empty"
            return false
        }
        
        if targetMuscle.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty {
            validationMessage = "Target muscle cannot be empty"
            return false
        }
        
        if manufacturer.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty {
            validationMessage = "Manufacturer cannot be empty"
            return false
        }
        
        return true
    }
    
    /// Saves or updates an exercise
    private func saveExercise() {
        if let existingExercise = exerciseToEdit {
            // Update existing exercise
            existingExercise.name = name.trimmingCharacters(in: .whitespacesAndNewlines)
            existingExercise.equipmentType = equipmentType
            existingExercise.targetMuscle = targetMuscle.trimmingCharacters(in: .whitespacesAndNewlines)
            existingExercise.manufacturer = manufacturer.trimmingCharacters(in: .whitespacesAndNewlines)
        } else {
            // Create new exercise
            let newExercise = Exercise(
                name: name.trimmingCharacters(in: .whitespacesAndNewlines),
                equipmentType: equipmentType,
                targetMuscle: targetMuscle.trimmingCharacters(in: .whitespacesAndNewlines),
                manufacturer: manufacturer.trimmingCharacters(in: .whitespacesAndNewlines)
            )
            modelContext.insert(newExercise)
        }
        
        try? modelContext.save()
    }
}

// MARK: - Exercise Detail View with 1RM Graph
struct ExerciseDetailView: View {
    @Environment(\.modelContext) private var modelContext
    var exercise: Exercise
    
    @State private var showingEditExercise = false
    
    // No Query property wrapper - we'll use the relationship directly
    
    // Prepare data for the 1RM chart directly from the relationship
    var oneRMData: [OneRMDataPoint] {
        guard let sets = exercise.sets else { return [] }
        
        return sets.compactMap { set in
            OneRMDataPoint(date: set.date, oneRM: set.oneRepMax)
        }
        .sorted { $0.date < $1.date }
    }
    
    // Get the recent sets
    var recentSets: [ExerciseSet] {
        guard let sets = exercise.sets else { return [] }
        let sortedSets = sets.sorted { $0.date > $1.date }
        return Array(sortedSets.prefix(5))
    }
    
    var body: some View {
        ScrollView {
            VStack(alignment: .leading, spacing: 16) {
                // Exercise details card
                VStack(alignment: .leading, spacing: 8) {
                    Text(exercise.fullName)
                        .font(.largeTitle)
                        .fontWeight(.bold)
                    
                    Text("Target muscle: \(exercise.targetMuscle)")
                        .font(.headline)
                }
                .padding()
                .frame(maxWidth: .infinity, alignment: .leading)
                .background(Color.secondary.opacity(0.1))
                .cornerRadius(10)
                
                // 1RM trend chart card
                VStack(alignment: .leading, spacing: 8) {
                    Text("One Rep Max Trend")
                        .font(.headline)
                    
                    if oneRMData.isEmpty {
                        Text("Complete a workout with this exercise to see your 1RM trend")
                            .foregroundColor(.secondary)
                            .frame(maxWidth: .infinity, alignment: .center)
                            .padding()
                    } else {
                        Chart(oneRMData) { dataPoint in
                            LineMark(
                                x: .value("Date", dataPoint.date),
                                y: .value("1RM", dataPoint.oneRM)
                            )
                            .foregroundStyle(Color.blue)
                            
                            PointMark(
                                x: .value("Date", dataPoint.date),
                                y: .value("1RM", dataPoint.oneRM)
                            )
                            .foregroundStyle(Color.blue)
                        }
                        .frame(height: 250)
                        .padding(.vertical)
                        .chartYAxis {
                            AxisMarks(position: .leading)
                        }
                    }
                }
                .padding()
                .background(Color.secondary.opacity(0.1))
                .cornerRadius(10)
                
                // Recent sets section
                if !recentSets.isEmpty {
                    VStack(alignment: .leading, spacing: 8) {
                        Text("Recent Sets")
                            .font(.headline)
                        
                        ForEach(Array(recentSets.enumerated()), id: \.element.id) { index, set in
                            HStack {
                                Text("\(index + 1).")
                                    .fontWeight(.bold)
                                
                                VStack(alignment: .leading) {
                                    Text("\(set.reps) reps × \(String(format: "%.1f", set.weight)) kg")
                                        .fontWeight(.medium)
                                    
                                    Text("RPE: \(set.rpe) • 1RM: \(String(format: "%.1f", set.oneRepMax)) kg")
                                        .font(.caption)
                                        .foregroundColor(.secondary)
                                    
                                    Text(set.date, style: .date)
                                        .font(.caption2)
                                        .foregroundColor(.secondary)
                                }
                                
                                Spacer()
                            }
                            .padding(.vertical, 4)
                        }
                    }
                    .padding()
                    .background(Color.secondary.opacity(0.1))
                    .cornerRadius(10)
                }
            }
            .padding()
        }
        .navigationTitle("Exercise Details")
        .toolbar {
            ToolbarItem(placement: .navigationBarTrailing) {
                Button(action: {
                    showingEditExercise = true
                }) {
                    Text("Edit")
                }
            }
        }
        .sheet(isPresented: $showingEditExercise) {
            NavigationStack {
                ExerciseFormView(isPresented: $showingEditExercise, exerciseToEdit: exercise)
                    .navigationTitle("Edit Exercise")
            }
        }
    }
}

// Data structure for 1RM chart
struct OneRMDataPoint: Identifiable {
    var id = UUID()
    var date: Date
    var oneRM: Double
}
