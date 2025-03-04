//
//  ExerciseSelectionView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//

import SwiftUI
import SwiftData

struct ExerciseSelectionView: View {
    @Environment(\.modelContext) private var modelContext
    @Environment(\.dismiss) private var dismiss
    @Query private var savedExercises: [SavedExercise]
    
    var workout: Workout
    @State private var newExerciseName = ""
    @State private var selectedType: ExerciseType = .dumbell
    
    var body: some View {
        NavigationStack {
            VStack {
                // Exercise type picker
                Picker("Exercise Type", selection: $selectedType) {
                    ForEach(ExerciseType.allCases) { type in
                        HStack {
                            Image(systemName: type.iconName)
                            Text(type.rawValue.capitalized)
                        }.tag(type)
                    }
                }
                .pickerStyle(.segmented)
                .padding()
                
                List {
                    Section("Add New Exercise") {
                        HStack {
                            TextField("Exercise name", text: $newExerciseName)
                            
                            Button(action: addCustomExercise) {
                                Image(systemName: "plus.circle.fill")
                            }
                        }
                    }
                    
                    Section("Saved Exercises") {
                        ForEach(savedExercises) { savedExercise in
                            Button(action: {
                                addExerciseToWorkout(name: savedExercise.name)
                            }) {
                                Text(savedExercise.name)
                            }
                        }
                    }
                }
            }
            .navigationTitle("Add Exercise")
            .toolbar {
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button("Done") {
                        dismiss()
                    }
                }
            }
        }
    }
    
    private func addCustomExercise() {
        guard !newExerciseName.isEmpty else { return }
        
        // Add to workout
        addExerciseToWorkout(name: newExerciseName)
        
        // Save to library if not already there
        if !savedExercises.contains(where: { $0.name == newExerciseName }) {
            let savedExercise = SavedExercise(name: newExerciseName)
            modelContext.insert(savedExercise)
        }
        
        newExerciseName = ""
    }
    
    private func addExerciseToWorkout(name: String) {
        let exercise = Exercise(name: name, type: selectedType.rawValue)
        exercise.workout = workout
        workout.exercises.append(exercise)
        dismiss()
    }
}
