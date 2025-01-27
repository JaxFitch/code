system_message = ""

def generate_meal_plan(profile):
    prompt = f"""
    Generate a meal plan for {profile['name']} who is a {profile['age']} 
    year old {profile['gender']} that weighs {profile['weight']} lbs and is 
    {profile['height']} inches tall. They have a {profile['activity_level']} 
    ifestyle and their goal is to {profile['goal']}. The meal plan should
    include breakfast, lunch, dinner, and snacks. It should also show all calories
    and macronutrients for each meal. 
    """
    return prompt

def generate_grocery_list(mealPlan):
    prompt = f"""
    Generate a grocery list for the following meal plan: {mealPlan}
    """
    return prompt

def changes(userChanges, mealPlan):
    prompt = f"""
    Make the following changes to this meal plan: {mealPlan}: 
   {userChanges}
    """
    return prompt