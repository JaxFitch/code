//
//  extensions-utilities.swift
//  lift3r
//
//  Created by Jackson Fitch on 3/5/25.
//


import SwiftUI
import SwiftData

// MARK: - View Extensions
extension View {
    /// Applies a conditional modifier
    @ViewBuilder func `if`<Content: View>(_ condition: Bool, transform: (Self) -> Content) -> some View {
        if condition {
            transform(self)
        } else {
            self
        }
    }
    
    /// Adds horizontal padding with a standard amount
    func hPadding() -> some View {
        self.padding(.horizontal, 16)
    }
    
    /// Creates a primary button style
    func primaryButton() -> some View {
        self
            .frame(maxWidth: .infinity)
            .padding()
            .background(Color.blue)
            .foregroundColor(.white)
            .cornerRadius(10)
            .padding(.horizontal)
    }
    
    /// Creates a secondary button style
    func secondaryButton() -> some View {
        self
            .frame(maxWidth: .infinity)
            .padding()
            .background(Color.secondary.opacity(0.1))
            .foregroundColor(.primary)
            .cornerRadius(10)
            .padding(.horizontal)
    }
    
    /// Creates a destructive button style
    func destructiveButton() -> some View {
        self
            .frame(maxWidth: .infinity)
            .padding()
            .background(Color.red)
            .foregroundColor(.white)
            .cornerRadius(10)
            .padding(.horizontal)
    }
}

// MARK: - Date Extensions
extension Date {
    /// Returns a string representation of the date in a readable format
    func formatted(style: DateFormatter.Style = .medium, showTime: Bool = true) -> String {
        let formatter = DateFormatter()
        formatter.dateStyle = style
        formatter.timeStyle = showTime ? .short : .none
        return formatter.string(from: self)
    }
    
    /// Returns a string for the day of the week
    var dayOfWeek: String {
        let formatter = DateFormatter()
        formatter.dateFormat = "EEEE"
        return formatter.string(from: self)
    }
    
    /// Returns a string for the month and day
    var monthAndDay: String {
        let formatter = DateFormatter()
        formatter.dateFormat = "MMM d"
        return formatter.string(from: self)
    }
    
    /// Returns a string for the time
    var timeString: String {
        let formatter = DateFormatter()
        formatter.dateFormat = "h:mm a"
        return formatter.string(from: self)
    }
}

// MARK: - String Extensions
extension String {
    /// Returns a trimmed string
    var trimmed: String {
        self.trimmingCharacters(in: .whitespacesAndNewlines)
    }
    
    /// Checks if the string is a valid number
    var isNumeric: Bool {
        Double(self) != nil
    }
}

// MARK: - Color Extensions
extension Color {
    /// Returns a color based on RPE value
    static func rpeColor(_ rpe: Int) -> Color {
        switch rpe {
        case 1...5:
            return .green
        case 6...7:
            return .blue
        case 8...9:
            return .orange
        case 10:
            return .red
        default:
            return .gray
        }
    }
}

// MARK: - ModelContext Extensions
extension ModelContext {
    /// Safely saves context and handles errors
    func safeSave() {
        do {
            try save()
        } catch {
            print("Error saving context: \(error)")
        }
    }
    
    /// Fetches objects with error handling
    func safeFetch<T>(_ descriptor: FetchDescriptor<T>) -> [T] {
        do {
            return try fetch(descriptor)
        } catch {
            print("Error fetching \(T.self): \(error)")
            return []
        }
    }
}

// MARK: - Image Extension
extension Image {
    /// Creates an icon with standard formatting
    func iconStyle(color: Color = .blue, size: CGFloat = 24) -> some View {
        self
            .resizable()
            .aspectRatio(contentMode: .fit)
            .frame(width: size, height: size)
            .foregroundColor(color)
    }
}

// MARK: - SwiftData Extension to handle Optional Arrays
extension Optional where Wrapped == [some Any] {
    /// Returns the count of an optional array or 0 if nil
    var count: Int {
        return self?.count ?? 0
    }
    
    /// Returns whether the optional array is empty or nil
    var isEmpty: Bool {
        return self?.isEmpty ?? true
    }
}