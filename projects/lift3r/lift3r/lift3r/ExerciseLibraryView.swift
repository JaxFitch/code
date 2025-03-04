//
//  ExerciseLibraryView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//

import SwiftUI
import SwiftData

struct ExerciseLibraryView: View {
    @Environment(\.modelContext) private var modelContext
    @Query private var savedExercises: [SavedExercise]
    
    @State private var newExerciseName = ""
    
    var body: some View {
        NavigationStack {
            VStack {
                HStack {
                    TextField("New exercise name", text: $newExerciseName)
                        .textFieldStyle(.roundedBorder)
                    
                    Button(action: addExercise) {
                        Image(systemName: "plus.circle.fill")
                            .font(.title2)
                    }
                }
                .padding()
                
                List {
                    ForEach(savedExercises) { exercise in
                        Text(exercise.name)
                    }
                    .onDelete(perform: deleteExercises)
                }
            }
            .navigationTitle("Exercise Library")
            .toolbar {
                EditButton()
            }
        }
    }
    
    private func addExercise() {
        guard !newExerciseName.isEmpty else { return }
        
        if !savedExercises.contains(where: { $0.name == newExerciseName }) {
            let savedExercise = SavedExercise(name: newExerciseName)
            modelContext.insert(savedExercise)
            newExerciseName = ""
        }
    }
    
    private func deleteExercises(at offsets: IndexSet) {
        for index in offsets {
            modelContext.delete(savedExercises[index])
        }
    }
}
