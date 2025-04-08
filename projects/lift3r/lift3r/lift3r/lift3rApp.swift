import SwiftUI
import SwiftData

// MARK: - Model Container Setup
extension ModelContainer {
    /// Creates a model container for the app with all required model types
    static var lift3rContainer: ModelContainer {
        let schema = Schema([
            User.self,
            Exercise.self,
            ExerciseSet.self,
            Workout.self
        ])
        
        let modelConfiguration = ModelConfiguration(
            schema: schema,
            isStoredInMemoryOnly: false,
            allowsSave: true
        )
        
        do {
            return try ModelContainer(for: schema, configurations: [modelConfiguration])
        } catch {
            // Handle any potential errors during container creation
            fatalError("Could not create ModelContainer: \(error)")
        }
    }
}

// MARK: - App Entry Point
@main
struct Lift3rApp: App {
    @State private var modelContainer = ModelContainer.lift3rContainer
    
    var body: some Scene {
        WindowGroup {
            ContentView()
                .modelContainer(modelContainer)
                .onAppear {
                    // Check for user existence on app launch
                    checkForUser()
                }
        }
    }
    
    /// Checks if a user exists in the database and creates one if not
    private func checkForUser() {
        let context = modelContainer.mainContext
        let fetchDescriptor = FetchDescriptor<User>()
        
        do {
            let users = try context.fetch(fetchDescriptor)
            if users.isEmpty {
                // Create a default user
                let defaultUser = User(name: "User", themePreference: .system)
                context.insert(defaultUser)
                try context.save()
                
                // Apply theme settings
                ThemeManager.applyTheme(.system)
            } else if let user = users.first {
                // Apply saved theme settings
                ThemeManager.applyTheme(user.themePreference)
            }
        } catch {
            print("Error checking for user: \(error)")
        }
    }
}

// MARK: - App Storage Keys
enum AppStorageKeys {
    static let userName = "userName"
    static let themePreference = "themePreference"
}

// MARK: - Theme Manager
class ThemeManager {
    static func applyTheme(_ preference: ThemePreference) {
        DispatchQueue.main.async {
            if let windowScene = UIApplication.shared.connectedScenes.first as? UIWindowScene {
                let interfaceStyle: UIUserInterfaceStyle
                
                switch preference {
                case .light:
                    interfaceStyle = .light
                case .dark:
                    interfaceStyle = .dark
                case .system:
                    interfaceStyle = .unspecified
                }
                
                windowScene.windows.forEach { window in
                    window.overrideUserInterfaceStyle = interfaceStyle
                }
            }
        }
    }
}