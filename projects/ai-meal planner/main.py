# Jackson Fitch
# 1/26/2025

import os
import openai
from dotenv import load_dotenv, find_dotenv

import prompts

# Load environment variables
load_dotenv(find_dotenv())
openai.api_key = os.getenv("OPENAI_API_KEY")

# Set parameters
model = "gpt-4o"
temperature = 0.3 # 0.0 - 1.0 (higher is more creative)
max_tokens = 1000

# Ask user for basic information and store it in a profile
profile = {}
profile["name"] = input("Name: ")
profile["age"] = input("Age: ")
profile["gender"] = input("Gender: ")
profile["weight"] = input("Weight (lbs): ")
profile["height"] = input("Height (inches): ")
profile["activity_level"] = input("Activity Level (sedentary, moderate, active): ")
profile["goal"] = input("Goal (lose weight, maintain weight, gain weight): ")

# Generate a meal plan based on the user's profile and use prompts.py file
prompt = prompts.generate_meal_plan(profile)
response = openai.chat.completions.create(
    model=model,
    messages=[
        {"role": "system", "content": "You are a dietitian assistant."},
        {"role": "user", "content": prompt}
    ],
    temperature=temperature,
    max_tokens=max_tokens
)

# Print the generated meal plan
print(response.choices[0].message.content)

# Save the generated meal plan to a variable
mealPlan = response.choices[0].message.content

# Ask the user if they have any changes to the meal plan
while True:
    userChanges = input("Do you have any changes to the meal plan? (yes/no): ")
    if userChanges.lower() == "no":
        break
    userChanges = input("What changes would you like to make? ")
    prompt = prompts.changes(userChanges, mealPlan)
    response = openai.chat.completions.create(
        model=model,
        messages=[
            {"role": "system", "content": "You are a dietitian assistant."},
            {"role": "user", "content": prompt}
        ],
        temperature=temperature,
        max_tokens=max_tokens
    )

    # Print the updated meal plan with the user's changes
    print(response.choices[0].message.content)

# Ask user if they would like to generate a grocery list
generateGroceryList = input("Would you like to generate a grocery list? (yes/no): ")

if generateGroceryList.lower() == "yes":
    prompt = prompts.generate_grocery_list(mealPlan)
    response = openai.chat.completions.create(
        model=model,
        messages=[
            {"role": "system", "content": "You are a dietitian assistant."},
            {"role": "user", "content": prompt}
        ],
        temperature=temperature,
        max_tokens=max_tokens
    )

    # Print the generated grocery list
    print(response.choices[0].message.content)
else:
    print("Thank you for using the AI Meal Planner!")
