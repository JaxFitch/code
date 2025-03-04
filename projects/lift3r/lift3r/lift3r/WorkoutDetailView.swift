//
//  WorkoutDetailView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//

import SwiftUI
import SwiftData

struct WorkoutDetailView: View {
    @Bindable var workout: Workout
    @State private var newExerciseName = ""
    @State private var selectedType: ExerciseType = .dumbell
    @Environment(\.modelContext) private var modelContext
    
    var body: some View {
        List {
            Section("Workout Info") {
                HStack {
                    Text("Date:")
                    Spacer()
                    Text(workout.startTime, format: .dateTime.day().month().year())
                }
                
                if let endTime = workout.endTime {
                    HStack {
                        Text("Duration:")
                        Spacer()
                        Text(formatDuration(from: workout.startTime, to: endTime))
                    }
                } else {
                    HStack {
                        Text("Status:")
                        Spacer()
                        Text("In progress")
                            .foregroundColor(.blue)
                    }
                }
            }
            
            Section("Exercises") {
                ForEach(workout.exercises) { exercise in
                    NavigationLink(value: exercise) {
                        HStack {
                            Image(systemName: ExerciseType(rawValue: exercise.type)?.iconName ?? "dumbbell")
                                .foregroundColor(.blue)
                            
                            VStack(alignment: .leading) {
                                Text(exercise.name)
                                    .font(.headline)
                                Text("\(exercise.sets.count) sets")
                                    .font(.subheadline)
                            }
                        }
                    }
                }
                .onDelete(perform: deleteExercises)
                
                if workout.endTime == nil {
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
                        .padding(.vertical, 8)
                        
                        HStack {
                            TextField("Add exercise", text: $newExerciseName)
                            
                            Button(action: addExercise) {
                                Image(systemName: "plus.circle.fill")
                            }
                        }
                    }
                }
            }
        }
        .navigationTitle("Workout Details")
        .navigationDestination(for: Exercise.self) { exercise in
            ExerciseDetailView(exercise: exercise)
        }
        .toolbar {
            if workout.endTime == nil {
                Button("End Workout") {
                    workout.endTime = Date()
                }
            }
        }
    }
    
    private func formatDuration(from start: Date, to end: Date) -> String {
        let diff = Int(end.timeIntervalSince(start))
        let hours = diff / 3600
        let minutes = (diff % 3600) / 60
        
        if hours > 0 {
            return "\(hours)h \(minutes)m"
        } else {
            return "\(minutes)m"
        }
    }
    
    private func addExercise() {
        guard !newExerciseName.isEmpty else { return }
        
        let exercise = Exercise(name: newExerciseName, type: selectedType.rawValue)
        exercise.workout = workout
        workout.exercises.append(exercise)
        
        newExerciseName = ""
    }
    
    private func deleteExercises(at offsets: IndexSet) {
        for index in offsets {
            let exercise = workout.exercises[index]
            workout.exercises.remove(at: index)
            modelContext.delete(exercise)
        }
    }
}
