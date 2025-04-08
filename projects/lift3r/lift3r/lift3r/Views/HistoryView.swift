//
//  HistoryView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/5/25.
//


import SwiftUI
import SwiftData

// MARK: - Main History View
struct HistoryView: View {
    @Environment(\.modelContext) private var modelContext
    // Get completed workouts (endTime is not nil)
    @Query(filter: #Predicate<Workout> { $0.endTime != nil },
           sort: [SortDescriptor(\Workout.startTime, order: .reverse)])
    private var completedWorkouts: [Workout]
    
    var body: some View {
        NavigationStack {
            List {
                if completedWorkouts.isEmpty {
                    ContentUnavailableView {
                        Label("No Workout History", systemImage: "clock.badge.exclamationmark")
                    } description: {
                        Text("Complete your first workout to see it here")
                    }
                } else {
                    ForEach(completedWorkouts) { workout in
                        NavigationLink(destination: WorkoutDetailView(workout: workout)) {
                            WorkoutHistoryRow(workout: workout)
                        }
                    }
                    .onDelete(perform: deleteWorkout)
                }
            }
            .navigationTitle("History")
            .toolbar {
                EditButton()
            }
        }
    }
    
    // MARK: - Helper Methods
    
    /// Deletes a workout from history
    private func deleteWorkout(at offsets: IndexSet) {
        for index in offsets {
            let workout = completedWorkouts[index]
            modelContext.delete(workout)
        }
        try? modelContext.save()
    }
}

// MARK: - Workout History Row
struct WorkoutHistoryRow: View {
    var workout: Workout
    
    // Date formatter for readable dates
    private let dateFormatter: DateFormatter = {
        let formatter = DateFormatter()
        formatter.dateStyle = .medium
        formatter.timeStyle = .short
        return formatter
    }()
    
    var body: some View {
        VStack(alignment: .leading, spacing: 4) {
            // Date of workout
            Text(dateFormatter.string(from: workout.startTime))
                .font(.headline)
            
            HStack {
                // Duration
                Label(
                    workout.duration.formattedDuration(),
                    systemImage: "clock"
                )
                
                Spacer()
                
                // Exercise count
                Label(
                    "\(workout.exercises?.count ?? 0) exercises",
                    systemImage: "dumbbell"
                )
            }
            .font(.caption)
            .foregroundColor(.secondary)
            
            // Preview of exercises
            if let exercises = workout.exercises, !exercises.isEmpty {
                Text(exercises.prefix(3).map { $0.name }.joined(separator: ", "))
                    .font(.caption2)
                    .foregroundColor(.secondary)
                    .lineLimit(1)
                    .padding(.top, 2)
            }
        }
        .padding(.vertical, 4)
    }
}

// MARK: - Workout Detail View
struct WorkoutDetailView: View {
    @Environment(\.modelContext) private var modelContext
    var workout: Workout
    
    @State private var isEditing = false
    @State private var showDeleteConfirmation = false
    
    // Date formatter
    private let dateFormatter: DateFormatter = {
        let formatter = DateFormatter()
        formatter.dateStyle = .long
        formatter.timeStyle = .short
        return formatter
    }()
    
    var body: some View {
        List {
            // MARK: - Workout Summary Section
            Section(header: Text("Summary")) {
                VStack(alignment: .leading, spacing: 12) {
                    // Date and time
                    HStack {
                        Image(systemName: "calendar")
                            .foregroundColor(.blue)
                        
                        Text(dateFormatter.string(from: workout.startTime))
                    }
                    
                    // Duration
                    HStack {
                        Image(systemName: "clock")
                            .foregroundColor(.blue)
                        
                        Text("Duration: \(workout.duration.formattedDuration())")
                    }
                    
                    // Exercise count
                    HStack {
                        Image(systemName: "dumbbell")
                            .foregroundColor(.blue)
                        
                        Text("\(workout.exercises?.count ?? 0) exercises")
                    }
                }
                .padding(.vertical, 8)
            }
            
            // MARK: - Exercises Section
            if let exercises = workout.exercises, !exercises.isEmpty {
                Section(header: Text("Exercises")) {
                    ForEach(exercises) { exercise in
                        WorkoutExerciseRow(workout: workout, exercise: exercise, isEditing: $isEditing)
                    }
                }
            } else {
                Section(header: Text("Exercises")) {
                    Text("No exercises recorded")
                        .foregroundColor(.secondary)
                        .frame(maxWidth: .infinity, alignment: .center)
                        .padding()
                }
            }
        }
        .navigationTitle("Workout Details")
        .toolbar {
            ToolbarItem(placement: .navigationBarTrailing) {
                Button(isEditing ? "Done" : "Edit") {
                    withAnimation {
                        isEditing.toggle()
                    }
                }
            }
            
            ToolbarItem(placement: .navigationBarTrailing) {
                Button(role: .destructive, action: {
                    showDeleteConfirmation = true
                }) {
                    Image(systemName: "trash")
                }
                .disabled(isEditing)
            }
        }
        .alert("Delete Workout", isPresented: $showDeleteConfirmation) {
            Button("Cancel", role: .cancel) {}
            Button("Delete", role: .destructive) {
                deleteWorkout()
            }
        } message: {
            Text("Are you sure you want to delete this workout? This action cannot be undone.")
        }
    }
    
    // MARK: - Helper Methods
    
    /// Deletes the workout
    private func deleteWorkout() {
        modelContext.delete(workout)
        try? modelContext.save()
    }
}

// MARK: - Workout Exercise Row
struct WorkoutExerciseRow: View {
    @Environment(\.modelContext) private var modelContext
    var workout: Workout
    var exercise: Exercise
    @Binding var isEditing: Bool
    
    // Get sets for this specific exercise in this specific workout
    var exerciseSets: [ExerciseSet] {
        workout.sets?.filter { $0.exercise?.id == exercise.id } ?? []
    }
    
    var body: some View {
        VStack(alignment: .leading, spacing: 8) {
            // Exercise name
            Text(exercise.fullName)
                .font(.headline)
            
            // Sets display
            if !exerciseSets.isEmpty {
                ForEach(exerciseSets) { set in
                    HStack {
                        if isEditing {
                            Button(action: {
                                deleteSet(set)
                            }) {
                                Image(systemName: "minus.circle.fill")
                                    .foregroundColor(.red)
                            }
                        }
                        
                        Text("\(set.reps) reps × \(String(format: "%.1f", set.weight)) kg")
                            .font(.subheadline)
                        
                        Spacer()
                        
                        Text("RPE \(set.rpe)")
                            .font(.caption)
                            .foregroundColor(.secondary)
                            .padding(.horizontal, 6)
                            .padding(.vertical, 2)
                            .background(Color.secondary.opacity(0.1))
                            .cornerRadius(4)
                    }
                    .transition(.opacity)
                    .animation(.easeInOut, value: isEditing)
                }
            } else {
                Text("No sets recorded")
                    .font(.caption)
                    .foregroundColor(.secondary)
            }
            
            // Edit buttons when in edit mode
            if isEditing {
                HStack {
                    Button(action: {
                        // We would implement editing exercise details here
                    }) {
                        Text("Edit Exercise")
                            .font(.caption)
                            .foregroundColor(.blue)
                    }
                    
                    Spacer()
                    
                    Button(action: {
                        deleteExercise()
                    }) {
                        Text("Delete")
                            .font(.caption)
                            .foregroundColor(.red)
                    }
                }
                .padding(.top, 4)
            }
        }
        .padding(.vertical, 4)
    }
    
    // MARK: - Helper Methods
    
    /// Deletes a set from the workout
    private func deleteSet(_ set: ExerciseSet) {
        // Remove from workout.sets
        if var sets = workout.sets {
            sets.removeAll { $0.id == set.id }
            workout.sets = sets
        }
        
        // Remove from exercise.sets
        if var exerciseSets = exercise.sets {
            exerciseSets.removeAll { $0.id == set.id }
            exercise.sets = exerciseSets
        }
        
        // Delete from database
        modelContext.delete(set)
        try? modelContext.save()
    }
    
    /// Deletes an exercise from the workout
    private func deleteExercise() {
        // Delete all sets for this exercise in this workout
        for set in exerciseSets {
            modelContext.delete(set)
        }
        
        // Remove exercise from workout
        if var exercises = workout.exercises {
            exercises.removeAll { $0.id == exercise.id }
            workout.exercises = exercises
        }
        
        try? modelContext.save()
    }
}
