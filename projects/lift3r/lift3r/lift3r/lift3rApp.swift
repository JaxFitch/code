//
//  lift3rApp.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/2/25.
//

import SwiftUI
import SwiftData

@main
struct lift3rApp: App {
    var sharedModelContainer: ModelContainer = {
        let schema = Schema([
            Workout.self,
            Exercise.self,
            ExerciseSet.self,
            SavedExercise.self,
            UserStats.self
        ])
        
        let modelConfiguration = ModelConfiguration(
            schema: schema,
            isStoredInMemoryOnly: false
            //cloudKitDatabase: .private("iCloud.jax.lift3r")
        )
        
        do {
            return try ModelContainer(for: schema, configurations: [modelConfiguration])
        } catch {
            fatalError("Could not create ModelContainer: \(error)")
        }
    }()
    
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
        .modelContainer(sharedModelContainer)
    }
}
