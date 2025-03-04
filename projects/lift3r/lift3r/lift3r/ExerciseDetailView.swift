//
//  ExerciseDetailView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//

import SwiftUI
import SwiftData
import Observation

struct ExerciseDetailView: View {
    @Bindable var exercise: Exercise
    @State private var reps = ""
    @State private var weight = ""
    
    var body: some View {
        VStack {
            List {
                ForEach(exercise.sets) { set in
                    HStack {
                        Text("\(set.reps) reps")
                        Spacer()
                        if let weight = set.weight {
                            Text("\(weight, specifier: "%.1f") lbs")
                        }
                    }
                }
                .onDelete(perform: deleteSets)
            }
            
            HStack {
                TextField("Reps", text: $reps)
                    .keyboardType(.numberPad)
                    .textFieldStyle(.roundedBorder)
                
                TextField("Weight (optional)", text: $weight)
                    .keyboardType(.decimalPad)
                    .textFieldStyle(.roundedBorder)
                
                Button(action: addSet) {
                    Image(systemName: "plus.circle.fill")
                        .font(.title2)
                }
            }
            .padding()
        }
        .navigationTitle(exercise.name)
    }
    
    private func addSet() {
        guard let repsInt = Int(reps), repsInt > 0 else { return }
        let weightDouble = Double(weight)
        
        let newSet = ExerciseSet(reps: repsInt, weight: weightDouble)
        newSet.exercise = exercise
        exercise.sets.append(newSet)
        
        reps = ""
        weight = ""
    }
    
    private func deleteSets(at offsets: IndexSet) {
        exercise.sets.remove(atOffsets: offsets)
    }
}
