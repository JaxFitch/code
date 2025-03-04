//
//  HistoryView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//

import SwiftUI
import SwiftData

struct HistoryView: View {
    @Environment(\.modelContext) private var modelContext
    @Query(sort: \Workout.startTime, order: .reverse) private var workouts: [Workout]
    
    var body: some View {
        NavigationStack {
            List {
                ForEach(workouts) { workout in
                    NavigationLink(value: workout) {
                        VStack(alignment: .leading) {
                            Text(workout.startTime, format: .dateTime.day().month().year())
                                .font(.headline)
                            
                            Text("\(workout.exercises.count) exercises")
                                .font(.subheadline)
                            
                            if let endTime = workout.endTime {
                                Text("Duration: \(formatDuration(from: workout.startTime, to: endTime))")
                                    .font(.caption)
                            } else {
                                Text("In progress")
                                    .font(.caption)
                                    .foregroundColor(.blue)
                            }
                        }
                    }
                }
                .onDelete(perform: deleteWorkouts)
            }
            .navigationDestination(for: Workout.self) { workout in
                WorkoutDetailView(workout: workout)
            }
            .navigationTitle("Workout History")
            .toolbar {
                EditButton()
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
    
    private func deleteWorkouts(at offsets: IndexSet) {
        for index in offsets {
            modelContext.delete(workouts[index])
        }
    }
}
