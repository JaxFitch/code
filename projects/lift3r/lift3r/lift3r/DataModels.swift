//
//  User.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/5/25.
//


import Foundation
import SwiftUI
import SwiftData

// MARK: - User Model
@Model
class User {
    var name: String
    var themePreference: ThemePreference
    
    init(name: String = "User", themePreference: ThemePreference = .system) {
        self.name = name
        self.themePreference = themePreference
    }
}

// MARK: - Theme Preference Enum
enum ThemePreference: String, Codable {
    case light, dark, system
}

// MARK: - Exercise Model
@Model
class Exercise {
    var id: UUID
    var name: String
    var equipmentType: EquipmentType
    var targetMuscle: String
    var manufacturer: String
    
    // Relationships
    @Relationship(deleteRule: .cascade, inverse: \ExerciseSet.exercise)
    var sets: [ExerciseSet]?
    
    // Computed property for full exercise name
    var fullName: String {
        return "\(manufacturer)-\(name)-\(equipmentType.rawValue)"
    }
    
    init(name: String, equipmentType: EquipmentType, targetMuscle: String, manufacturer: String) {
        self.id = UUID()
        self.name = name
        self.equipmentType = equipmentType
        self.targetMuscle = targetMuscle
        self.manufacturer = manufacturer
        self.sets = []
    }
}

// MARK: - Equipment Type Enum
enum EquipmentType: String, Codable {
    case cable = "Cable"
    case machine = "Machine"
    case freeweight = "Freeweight"
}

// MARK: - Exercise Set Model
@Model
class ExerciseSet {
    var id: UUID
    var reps: Int
    var weight: Double
    var rpe: Int // Rate of Perceived Exertion
    var date: Date
    
    // Relationships
    var exercise: Exercise?
    var workout: Workout?
    
    // Calculate one rep max using the formula: 1RM = Weight × (1 + 0.0333 x number of reps)
    var oneRepMax: Double {
        return weight * (1 + 0.0333 * Double(reps))
    }
    
    init(reps: Int, weight: Double, rpe: Int) {
        self.id = UUID()
        self.reps = reps
        self.weight = weight
        self.rpe = rpe
        self.date = Date()
    }
}

// MARK: - Workout Model
@Model
class Workout {
    var id: UUID
    var startTime: Date
    var endTime: Date?
    
    // Relationships
    @Relationship(deleteRule: .cascade, inverse: \ExerciseSet.workout)
    var sets: [ExerciseSet]?
    var exercises: [Exercise]?
    
    // Calculate workout duration
    var duration: TimeInterval {
        if let endTime = endTime {
            return endTime.timeIntervalSince(startTime)
        } else {
            return Date().timeIntervalSince(startTime)
        }
    }
    
    init(startTime: Date = Date()) {
        self.id = UUID()
        self.startTime = startTime
        self.exercises = []
        self.sets = []
    }
}

// MARK: - TimeInterval Extension for formatting duration
extension TimeInterval {
    func formattedDuration() -> String {
        let hours = Int(self) / 3600
        let minutes = (Int(self) % 3600) / 60
        let seconds = Int(self) % 60
        
        if hours > 0 {
            return String(format: "%d:%02d:%02d", hours, minutes, seconds)
        } else {
            return String(format: "%02d:%02d", minutes, seconds)
        }
    }
}