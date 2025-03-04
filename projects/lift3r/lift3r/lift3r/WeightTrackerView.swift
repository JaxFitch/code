//
//  WeightTrackerView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//

import SwiftUI
import SwiftData

struct WeightTrackerView: View {
    @Environment(\.modelContext) private var modelContext
    @Query(sort: \UserStats.date, order: .reverse) private var stats: [UserStats]
    
    @State private var currentWeight = ""
    @State private var goalWeight = ""
    
    var body: some View {
        NavigationStack {
            Form {
                Section("Update Weight") {
                    TextField("Current Weight (lbs)", text: $currentWeight)
                        .keyboardType(.decimalPad)
                    
                    TextField("Goal Weight (lbs)", text: $goalWeight)
                        .keyboardType(.decimalPad)
                    
                    Button("Save") {
                        saveWeightStats()
                    }
                    .frame(maxWidth: .infinity, alignment: .center)
                }
                
                Section("Weight History") {
                    ForEach(stats) { stat in
                        VStack(alignment: .leading) {
                            Text(stat.date, format: .dateTime.day().month().year())
                                .font(.headline)
                            
                            HStack {
                                if let current = stat.currentWeight {
                                    Text("Current: \(current, specifier: "%.1f") lbs")
                                }
                                
                                Spacer()
                                
                                if let goal = stat.goalWeight {
                                    Text("Goal: \(goal, specifier: "%.1f") lbs")
                                }
                            }
                            .font(.subheadline)
                        }
                    }
                }
            }
            .navigationTitle("Weight Tracker")
        }
        .onAppear {
            if let latest = stats.first {
                if let current = latest.currentWeight {
                    currentWeight = String(format: "%.1f", current)
                }
                if let goal = latest.goalWeight {
                    goalWeight = String(format: "%.1f", goal)
                }
            }
        }
    }
    
    private func saveWeightStats() {
        let currentWeightDouble = Double(currentWeight)
        let goalWeightDouble = Double(goalWeight)
        
        if currentWeightDouble != nil || goalWeightDouble != nil {
            let newStats = UserStats(currentWeight: currentWeightDouble, goalWeight: goalWeightDouble)
            modelContext.insert(newStats)
            
            // Clear fields
            currentWeight = currentWeightDouble != nil ? currentWeight : ""
            goalWeight = goalWeightDouble != nil ? goalWeight : ""
        }
    }
}
