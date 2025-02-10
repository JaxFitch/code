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
    Follow this formatting but dont just copy this example:
    2200 180g 220g 70g
    """

    return prompt

def generate_breakfast(calories, protein, carbs, fats):
    prompt = f"""
    Generate a breakfast meal that fits within {calories} calories with {protein} of protein, {carbs} of carbs, and {fats} of fats.
    Theses calories are the users total daily calories and the macros are the total daily macros. Only generate one meal. 
    Only return the meal and ingredients with no extra wording and include the macros of each ingredient in the meal and the total 
    macros of the meal. Keep in mind that they have to eat lunch and dinner and maybe some snacks so dont make it to big. Display in html format. 
    Dont come up with a breakfast bowl everytime, use some creativity.
    
    Also make sure to have it in a list format like the example below but dont just copy this example:

    Title of meal:

	•	Name of submeal
			•	Ingredient 1: # calories, #g protein, #g carbs, #g fat
			•	Ingredient 2: # calories, #g protein, #g carbs, #g fat
			•	Ingredient 3: # calories, #g protein, #g carbs, #g fat
	•	Name of submeal
            •	Ingredient 1: # calories, #g protein, #g carbs, #g fat
            •	Ingredient 2: # calories, #g protein, #g carbs, #g fat
            •	Ingredient 3: # calories, #g protein, #g carbs, #g fat
	•	Name of submeal
            •	Ingredient 1: # calories, #g protein, #g carbs, #g fat
            •	Ingredient 2: # calories, #g protein, #g carbs, #g fat
            •	Ingredient 3: # calories, #g protein, #g carbs, #g fat

Total Macros:
	•	Total Calories: #
	•	Total Protein: #g
	•	Total Carbs: #g
	•	Total Fat: #g
    """
    return prompt