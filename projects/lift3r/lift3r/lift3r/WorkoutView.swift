//
//  WorkoutView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//

import SwiftUI
import SwiftData

struct WorkoutView: View {
    @Environment(\.modelContext) private var modelContext
    @Query private var savedExercises: [SavedExercise]
    
    @State private var activeWorkout: Workout?
    @State private var showingExerciseSheet = false
    
    var body: some View {
        NavigationStack {
            VStack {
                if let workout = activeWorkout {
                    // Active workout view
                    List {
                        ForEach(workout.exercises) { exercise in
                            NavigationLink(destination: ExerciseDetailView(exercise: exercise)) {
                                VStack(alignment: .leading) {
                                    Text(exercise.name)
                                        .font(.headline)
                                    Text("\(exercise.sets.count) sets")
                                        .font(.subheadline)
                                }
                            }
                        }
                    }
                    .listStyle(.insetGrouped)
                    
                    Button("Add Exercise") {
                        showingExerciseSheet = true
                    }
                    .buttonStyle(.borderedProminent)
                    .padding()
                    
                    Button("End Workout") {
                        activeWorkout?.endTime = Date()
                        activeWorkout = nil
                    }
                    .buttonStyle(.bordered)
                    .padding(.bottom)
                } else {
                    // No active workout view
                    VStack(spacing: 20) {
                        Image(systemName: "figure.run")
                            .font(.system(size: 80))
                            .foregroundColor(.blue)
                        
                        Text("Ready to start your workout?")
                            .font(.title2)
                        
                        Button("Start Workout") {
                            let newWorkout = Workout(startTime: Date())
                            modelContext.insert(newWorkout)
                            activeWorkout = newWorkout
                        }
                        .buttonStyle(.borderedProminent)
                        .padding()
                    }
                    .padding(.vertical, 100)
                }
            }
            .navigationTitle("Workout")
            .sheet(isPresented: $showingExerciseSheet) {
                ExerciseSelectionView(workout: activeWorkout!)
            }
        }
    }
}
