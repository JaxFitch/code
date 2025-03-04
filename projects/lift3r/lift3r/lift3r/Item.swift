//
//  Item.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/2/25.
//

import Foundation
import SwiftData

@Model
final class Workout {
    var startTime: Date
    var endTime: Date?
    var exercises: [Exercise] = []
    
    init(startTime: Date) {
        self.startTime = startTime
    }
}

@Model
final class Exercise {
    var name: String
    var sets: [ExerciseSet] = []
    var workout: Workout?
    var type: String
    
    init(name: String, type: String = ExerciseType.dumbell.rawValue) {
        self.name = name
        self.type = type
    }
}

@Model
final class ExerciseSet {
    var reps: Int
    var weight: Double?
    var exercise: Exercise?
    
    init(reps: Int, weight: Double? = nil) {
        self.reps = reps
        self.weight = weight
    }
}

@Model
final class SavedExercise {
    var name: String
    
    init(name: String) {
        self.name = name
    }
}

@Model
final class UserStats {
    var currentWeight: Double?
    var goalWeight: Double?
    var date: Date
    
    init(currentWeight: Double? = nil, goalWeight: Double? = nil) {
        self.currentWeight = currentWeight
        self.goalWeight = goalWeight
        self.date = Date()
    }
}
