//
//  ExerciseType.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/4/25.
//


import SwiftUI

enum ExerciseType: String, CaseIterable, Identifiable {
    case dumbell, cables, machine
    
    var id: String { self.rawValue }
    
    var iconName: String {
        switch self {
        case .dumbell: return "dumbbell"
        case .cables: return "figure.strengthtraining.functional"
        case .machine: return "figure.strengthtraining.traditional"
        }
    }
}
