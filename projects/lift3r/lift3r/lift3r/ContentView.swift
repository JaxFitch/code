//
//  ContentView.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/2/25.
//

import SwiftUI
import SwiftData

struct ContentView: View {
    @State private var selectedTab = 0
    
    var body: some View {
        TabView(selection: $selectedTab) {
            WorkoutView()
                .tabItem {
                    Label("Workout", systemImage: "figure.run")
                }
                .tag(0)
            
            HistoryView()
                .tabItem {
                    Label("History", systemImage: "clock")
                }
                .tag(1)
            
            ExerciseLibraryView()
                .tabItem {
                    Label("Exercises", systemImage: "list.bullet")
                }
                .tag(2)
            
            WeightTrackerView()
                .tabItem {
                    Label("Weight", systemImage: "scalemass")
                }
                .tag(3)
        }
    }
}

