import SwiftUI
import SwiftData

// MARK: - Home View (Main Workout Tab)
struct HomeView: View {
    @Environment(\.modelContext) private var modelContext
    @Query private var users: [User]
    @Query(filter: #Predicate<Workout> { $0.endTime == nil }) private var activeWorkouts: [Workout]
    
    @State private var activeWorkout: Workout?
    
    var userName: String {
        users.first?.name ?? "User"
    }
    
    var isWorkoutActive: Bool {
        activeWorkout != nil
    }
    
    var body: some View {
        NavigationStack {
            VStack {
                if isWorkoutActive, let workout = activeWorkout {
                    // Show active workout
                    ActiveWorkoutView(workout: workout, onEnd: endWorkout)
                } else {
                    // Show welcome screen
                    WelcomeView(userName: userName, onStartWorkout: startNewWorkout)
                }
            }
            .navigationTitle("lift3r")
            .onAppear {
                // Check for any active workouts (no end time)
                checkForActiveWorkouts()
            }
        }
    }
    
    // MARK: - Helper Methods
    
    /// Checks if there's any active workout and sets it
    private func checkForActiveWorkouts() {
        if !activeWorkouts.isEmpty {
            activeWorkout = activeWorkouts.first
        }
    }
    
    /// Starts a new workout
    private func startNewWorkout() {
        let newWorkout = Workout(startTime: Date())
        modelContext.insert(newWorkout)
        try? modelContext.save()
        activeWorkout = newWorkout
    }
    
    /// Ends the current workout
    private func endWorkout() {
        guard let workout = activeWorkout else { return }
        workout.endTime = Date()
        try? modelContext.save()
        activeWorkout = nil
    }
}

// MARK: - Welcome View
struct WelcomeView: View {
    var userName: String
    var onStartWorkout: () -> Void
    
    var body: some View {
        VStack(spacing: 30) {
            // Welcome message with animation
            VStack(spacing: 10) {
                Text("Welcome")
                    .font(.largeTitle)
                    .fontWeight(.bold)
                
                Text(userName)
                    .font(.title)
                    .foregroundColor(.blue)
            }
            .padding()
            .transition(.scale.combined(with: .opacity))
            
            Spacer()
            
            // Motivational quote
            VStack {
                Text(""The only bad workout is the one that didn't happen."")
                    .font(.headline)
                    .italic()
                    .multilineTextAlignment(.center)
                    .padding()
            }
            
            Spacer()
            
            // Start workout button
            Button(action: onStartWorkout) {
                HStack {
                    Image(systemName: "play.fill")
                    Text("Start New Workout")
                        .fontWeight(.semibold)
                }
                .padding()
                .frame(maxWidth: .infinity)
                .background(Color.blue)
                .foregroundColor(.white)
                .cornerRadius(10)
            }
            .padding(.horizontal)
            .padding(.bottom, 30)
        }
    }
}

// MARK: - Active Workout View
struct ActiveWorkoutView: View {
    @Environment(\.modelContext) private var modelContext
    @ObservedObject var workout: Workout
    var onEnd: () -> Void
    
    @State private var showingExerciseSelector = false
    @State private var showingEndConfirmation = false
    @State private var elapsedTime = 0
    @State private var timer: Timer? = nil
    
    var formattedTime: String {
        let hours = elapsedTime / 3600
        let minutes = (elapsedTime % 3600) / 60
        let seconds = elapsedTime % 60
        
        if hours > 0 {
            return String(format: "%d:%02d:%02d", hours, minutes, seconds)
        } else {
            return String(format: "%02d:%02d", minutes, seconds)
        }
    }
    
    var body: some View {
        VStack {
            // Timer display
            VStack {
                Text("Workout in Progress")
                    .font(.headline)
                
                Text(formattedTime)
                    .font(.system(size: 50, weight: .bold, design: .monospaced))
                    .padding()
            }
            .padding()
            
            // Exercise list
            List {
                if let exercises = workout.exercises, !exercises.isEmpty {
                    ForEach(exercises) { exercise in
                        ExerciseInWorkoutRow(workout: workout, exercise: exercise)
                    }
                    .onDelete(perform: removeExercise)
                } else {
                    Text("No exercises added yet")
                        .foregroundColor(.secondary)
                        .frame(maxWidth: .infinity, alignment: .center)
                        .padding()
                }
            }
            .listStyle(InsetGroupedListStyle())
            
            // Control buttons
            HStack {
                Button(action: {
                    showingExerciseSelector = true
                }) {
                    HStack {
                        Image(systemName: "plus")
                        Text("Add Exercise")
                    }
                    .padding()
                    .frame(maxWidth: .infinity)
                    .background(Color.blue)
                    .foregroundColor(.white)
                    .cornerRadius(10)
                }
                
                Button(action: {
                    showingEndConfirmation = true
                }) {
                    HStack {
                        Image(systemName: "stop.fill")
                        Text("End Workout")
                    }
                    .padding()
                    .frame(maxWidth: .infinity)
                    .background(Color.red)
                    .foregroundColor(.white)
                    .cornerRadius(10)
                }
            }
            .padding()
        }
        .sheet(isPresented: $showingExerciseSelector) {
            NavigationStack {
                ExerciseSelectorView(workout: workout)
                    .navigationTitle("Select Exercise")
            }
        }
        .alert("End Workout", isPresented: $showingEndConfirmation) {
            Button("Cancel", role: .cancel) {}
            Button("End", role: .destructive) {
                timer?.invalidate()
                onEnd()
            }
        } message: {
            Text("Are you sure you want to end this workout?")
        }
        .onAppear {
            startTimer()
            calculateElapsedTime()
        }
        .onDisappear {
            timer?.invalidate()
        }
    }
    
    // MARK: - Helper Methods
    
    /// Starts the workout timer
    private func startTimer() {
        timer = Timer.scheduledTimer(withTimeInterval: 1, repeats: true) { _ in
            elapsedTime += 1
        }
    }
    
    /// Calculates elapsed time from workout start
    private func calculateElapsedTime() {
        elapsedTime = Int(Date().timeIntervalSince(workout.startTime))
    }
    
    /// Removes an exercise from the workout
    private func removeExercise(at offsets: IndexSet) {
        guard var exercises = workout.exercises else { return }
        
        for index in offsets {
            if index < exercises.count {
                // Also remove all sets associated with this exercise in the workout
                if let sets = workout.sets {
                    let exerciseToRemove = exercises[index]
                    workout.sets = sets.filter { $0.exercise?.id != exerciseToRemove.id }
                }
            }
        }
        
        // Remove exercises from the array
        for index in offsets {
            if index < exercises.count {
                exercises.remove(at: index)
            }
        }
        
        workout.exercises = exercises
        try? modelContext.save()
    }
}

// MARK: - Exercise in Workout Row
struct ExerciseInWorkoutRow: View {
    @Environment(\.modelContext) private var modelContext
    @ObservedObject var workout: Workout
    @ObservedObject var exercise: Exercise
    
    @State private var showingSetForm = false
    
    // Get sets for this specific exercise in this workout
    var exerciseSets: [ExerciseSet] {
        workout.sets?.filter { $0.exercise?.id == exercise.id } ?? []
    }
    
    var body: some View {
        VStack(alignment: .leading, spacing: 6) {
            Text(exercise.fullName)
                .font(.headline)
            
            if exerciseSets.isEmpty {
                Text("No sets recorded")
                    .font(.subheadline)
                    .foregroundColor(.secondary)
            } else {
                ForEach(exerciseSets) { set in
                    HStack {
                        Text("\(set.reps) reps")
                        Text("•")
                        Text("\(String(format: "%.1f", set.weight)) kg")
                        Text("•")
                        Text("RPE \(set.rpe)")
                    }
                    .font(.subheadline)
                    .foregroundColor(.secondary)
                }
            }
            
            Button(action: {
                showingSetForm = true
            }) {
                Text("Add Set")
                    .font(.footnote)
                    .foregroundColor(.blue)
            }
            .padding(.top, 4)
        }
        .padding(.vertical, 4)
        .sheet(isPresented: $showingSetForm) {
            NavigationStack {
                SetFormView(
                    workout: workout,
                    exercise: exercise,
                    isPresented: $showingSetForm
                )
                .navigationTitle("Add Set")
            }
        }
    }
}

// MARK: - Exercise Selector View
struct ExerciseSelectorView: View {
    @Environment(\.modelContext) private var modelContext
    @Environment(\.dismiss) private var dismiss
    @ObservedObject var workout: Workout
    
    @Query private var exercises: [Exercise]
    @State private var searchText = ""
    @State private var showingAddExercise = false
    
    var filteredExercises: [Exercise] {
        if searchText.isEmpty {
            return exercises
        } else {
            return exercises.filter { exercise in
                exercise.fullName.localizedCaseInsensitiveContains(searchText) ||
                exercise.targetMuscle.localizedCaseInsensitiveContains(searchText)
            }
        }
    }
    
    var body: some View {
        List {
            Section {
                Button(action: {
                    showingAddExercise = true
                }) {
                    HStack {
                        Image(systemName: "plus.circle.fill")
                        Text("Create New Exercise")
                    }
                }
            }
            
            Section(header: Text("Available Exercises")) {
                if filteredExercises.isEmpty {
                    Text("No exercises found")
                        .foregroundColor(.secondary)
                } else {
                    ForEach(filteredExercises) { exercise in
                        Button(action: {
                            addExerciseToWorkout(exercise)
                            dismiss()
                        }) {
                            VStack(alignment: .leading) {
                                Text(exercise.fullName)
                                    .foregroundColor(.primary)
                                
                                Text("Target: \(exercise.targetMuscle)")
                                    .font(.caption)
                                    .foregroundColor(.secondary)
                            }
                        }
                    }
                }
            }
        }
        .searchable(text: $searchText, prompt: "Search exercises")
        .sheet(isPresented: $showingAddExercise) {
            NavigationStack {
                NewExerciseInWorkoutView(workout: workout, dismissParent: {
                    dismiss()
                })
                .navigationTitle("New Exercise")
            }
        }
    }
    
    /// Adds an exercise to the current workout
    private func addExerciseToWorkout(_ exercise: Exercise) {
        if workout.exercises == nil {
            workout.exercises = []
        }
        
        // Check if exercise is already in the workout
        if let exercises = workout.exercises,
           !exercises.contains(where: { $0.id == exercise.id }) {
            workout.exercises?.append(exercise)
            try? modelContext.save()
        }
    }
}

// MARK: - New Exercise in Workout View
struct NewExerciseInWorkoutView: View {
    @Environment(\.modelContext) private var modelContext
    @Environment(\.dismiss) private var dismiss
    @ObservedObject var workout: Workout
    var dismissParent: () -> Void
    
    @State private var name = ""
    @State private var equipmentType = EquipmentType.freeweight
    @State private var targetMuscle = ""
    @State private var manufacturer = ""
    
    var body: some View {
        Form {
            Section(header: Text("Exercise Details")) {
                TextField("Name", text: $name)
                
                Picker("Equipment Type", selection: $equipmentType) {
                    Text("Cable").tag(EquipmentType.cable)
                    Text("Machine").tag(EquipmentType.machine)
                    Text("Freeweight").tag(EquipmentType.freeweight)
                }
                
                TextField("Target Muscle", text: $targetMuscle)
                TextField("Manufacturer", text: $manufacturer)
            }
            
            Section {
                Button("Add to Workout") {
                    let newExercise = createExercise()
                    if let newExercise = newExercise {
                        addExerciseToWorkout(newExercise)
                        dismiss()
                        dismissParent()
                    }
                }
                .frame(maxWidth: .infinity, alignment: .center)
                .disabled(!isFormValid)
            }
        }
    }
    
    private var isFormValid: Bool {
        !name.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty &&
        !targetMuscle.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty &&
        !manufacturer.trimmingCharacters(in: .whitespacesAndNewlines).isEmpty
    }
    
    /// Creates a new exercise
    private func createExercise() -> Exercise? {
        guard isFormValid else { return nil }
        
        let newExercise = Exercise(
            name: name.trimmingCharacters(in: .whitespacesAndNewlines),
            equipmentType: equipmentType,
            targetMuscle: targetMuscle.trimmingCharacters(in: .whitespacesAndNewlines),
            manufacturer: manufacturer.trimmingCharacters(in: .whitespacesAndNewlines)
        )
        
        modelContext.insert(newExercise)
        try? modelContext.save()
        
        return newExercise
    }
    
    /// Adds an exercise to the current workout
    private func addExerciseToWorkout(_ exercise: Exercise) {
        if workout.exercises == nil {
            workout.exercises = []
        }
        
        workout.exercises?.append(exercise)
        try? modelContext.save()
    }
}

// MARK: - Set Form View
struct SetFormView: View {
    @Environment(\.modelContext) private var modelContext
    @Environment(\.dismiss) private var dismiss
    @ObservedObject var workout: Workout
    @ObservedObject var exercise: Exercise
    @Binding var isPresented: Bool
    
    @State private var reps: String = ""
    @State private var weight: String = ""
    @State private var rpe: Int = 7
    
    @State private var showAlert = false
    @State private var alertMessage = ""
    
    var body: some View {
        Form {
            Section(header: Text("Set Details")) {
                TextField("Reps", text: $reps)
                    .keyboardType(.numberPad)
                
                TextField("Weight (kg)", text: $weight)
                    .keyboardType(.decimalPad)
                
                Stepper("RPE: \(rpe)", value: $rpe, in: 1...10)
                
                // RPE explanation
                VStack(alignment: .leading, spacing: 4) {
                    Text("Rate of Perceived Exertion (RPE):")
                        .font(.caption)
                        .foregroundColor(.secondary)
                    
                    Text("10 = Maximum effort, 7 = Could do 3 more reps")
                        .font(.caption2)
                        .foregroundColor(.secondary)
                }
                .padding(.top, 4)
            }
            
            Section {
                Button("Add Set") {
                    if validateForm() {
                        addSet()
                        isPresented = false
                    } else {
                        showAlert = true
                    }
                }
                .frame(maxWidth: .infinity, alignment: .center)
            }
        }
        .alert("Invalid Input", isPresented: $showAlert) {
            Button("OK", role: .cancel) {}
        } message: {
            Text(alertMessage)
        }
    }
    
    /// Validates form input
    private func validateForm() -> Bool {
        guard let repsInt = Int(reps), repsInt > 0 else {
            alertMessage = "Please enter a valid number of reps"
            return false
        }
        
        guard let weightDouble = Double(weight), weightDouble > 0 else {
            alertMessage = "Please enter a valid weight"
            return false
        }
        
        return true
    }
    
    /// Adds a new set to the exercise and workout
    private func addSet() {
        if let repsInt = Int(reps), let weightDouble = Double(weight) {
            let newSet = ExerciseSet(reps: repsInt, weight: weightDouble, rpe: rpe)
            newSet.exercise = exercise
            newSet.workout = workout
            
            if workout.sets == nil {
                workout.sets = []
            }
            
            workout.sets?.append(newSet)
            
            if exercise.sets == nil {
                exercise.sets = []
            }
            
            exercise.sets?.append(newSet)
            
            try? modelContext.save()
        }
    }
}