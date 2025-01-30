system_message = ""

def get_macros(profile):
    prompt = f"""
    You are a extremely accurate dietitian assistant. This is your clients profile: 
    Name: {profile['name']}
    Age: {profile['age']}
    Gender: {profile['gender']}
    Weight: {profile['weight']} lbs
    Height: {profile['height']} inches
    Activity Level: {profile['activity_level']}
    Goal: {profile['goal']}
    I want you to tell me the exact amount of calories and macronutrients for this person per day
    and return them in a list format with no bullet points or numbers or dashes and no other text.
    return the calories first then protein, carbs, and fats in that order seperated by one space and dont label them
    but do add "g" to the end of the macros but not calories keep the protein high and the fats moderate and the carbs 
    moderate. Make sure the totals add up to the amount of calories calculated for the user's goal.
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