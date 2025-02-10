# Jackson Fitch
# 1/26/2025

import os
import openai
from dotenv import load_dotenv, find_dotenv
import tkinter as tk
import customtkinter as ctk
import prompts
import markdown
import tkhtmlview
load_dotenv(find_dotenv())
openai.api_key = os.getenv("OPENAI_API_KEY")

# Set parameters
model = "gpt-4o-mini" # "gpt-4o-mini" or "gpt-4o"
temperature = 0.4 # 0.0 - 1.0 (higher is more creative)
max_tokens = 1000 # maximum number of tokens to generate

class MealPlannerApp(ctk.CTk):
    def __init__(self):
        super().__init__()

        ctk.set_appearance_mode("system")
        ctk.set_default_color_theme("green")

        self.title("AI Meal Planner")
        self.geometry("400x750")

        self.profile = {}

        self.create_widgets()

    def create_widgets(self):
        self.name_label = ctk.CTkLabel(self, text="Name:")
        self.name_label.pack(pady=5)
        self.name_entry = ctk.CTkEntry(self, justify='center')
        self.name_entry.pack(pady=5)

        self.age_label = ctk.CTkLabel(self, text="Age:")
        self.age_label.pack(pady=5)
        self.age_entry = ctk.CTkEntry(self, justify='center')
        self.age_entry.pack(pady=5)

        self.weight_label = ctk.CTkLabel(self, text="Weight (lbs):")
        self.weight_label.pack(pady=5)
        self.weight_entry = ctk.CTkEntry(self, justify='center')
        self.weight_entry.pack(pady=5)

        self.height_label = ctk.CTkLabel(self, text="Height (inches):")
        self.height_label.pack(pady=5)
        self.height_entry = ctk.CTkEntry(self, justify='center')
        self.height_entry.pack(pady=5)

        self.gender_label = ctk.CTkLabel(self, text="Gender:")
        self.gender_label.pack(pady=5)
        self.gender_var = tk.StringVar(value="male")
        self.male_button = ctk.CTkRadioButton(self, text="Male", variable=self.gender_var, value="male")
        self.male_button.pack(pady=5)
        self.female_button = ctk.CTkRadioButton(self, text="Female", variable=self.gender_var, value="female")
        self.female_button.pack(pady=5)

        self.activity_level_label = ctk.CTkLabel(self, text="Activity Level:")
        self.activity_level_label.pack(pady=5)
        self.activity_level_var = tk.StringVar(value="moderate")
        self.sedentary_button = ctk.CTkRadioButton(self, text="Sedentary", variable=self.activity_level_var, value="sedentary")
        self.sedentary_button.pack(pady=5)
        self.moderate_button = ctk.CTkRadioButton(self, text="Moderate", variable=self.activity_level_var, value="moderate")
        self.moderate_button.pack(pady=5)
        self.active_button = ctk.CTkRadioButton(self, text="Active", variable=self.activity_level_var, value="active")
        self.active_button.pack(pady=5)

        self.goal_label = ctk.CTkLabel(self, text="Goal:")
        self.goal_label.pack(pady=5)
        self.goal_var = tk.StringVar(value="maintain weight")
        self.lose_weight_button = ctk.CTkRadioButton(self, text="Lose Weight", variable=self.goal_var, value="lose weight")
        self.lose_weight_button.pack(pady=5)
        self.maintain_weight_button = ctk.CTkRadioButton(self, text="Maintain Weight", variable=self.goal_var, value="maintain weight")
        self.maintain_weight_button.pack(pady=5)
        self.gain_weight_button = ctk.CTkRadioButton(self, text="Gain Weight", variable=self.goal_var, value="gain weight")
        self.gain_weight_button.pack(pady=5)

        self.generate_button = ctk.CTkButton(self, text="Generate Meal Plan", command=self.get_macros)
        self.generate_button.pack(pady=20)

    def get_macros(self):
        self.profile["name"] = self.name_entry.get()
        self.profile["age"] = self.age_entry.get()
        self.profile["weight"] = self.weight_entry.get()
        self.profile["height"] = self.height_entry.get()
        self.profile["gender"] = self.gender_var.get()
        self.profile["activity_level"] = self.activity_level_var.get()
        self.profile["goal"] = self.goal_var.get()

        for widget in self.winfo_children():
            widget.destroy()

        self.geometry("700x800")

        prompt = prompts.get_macros(self.profile)
        response = openai.chat.completions.create(
            model=model,
            messages=[
                {"role": "system", "content": "You are a dietitian assistant."},
                {"role": "user", "content": prompt}
            ],
            temperature=temperature,
            max_tokens=max_tokens
        )

        macros = response.choices[0].message.content
        self.totalCalories = macros.split(" ")[0]
        self.totalProtein = macros.split(" ")[1]
        self.totalCarbs = macros.split(" ")[2]
        self.totalFats = macros.split(" ")[3]

        self.calories_label = ctk.CTkLabel(self, text=f"Calories: {self.totalCalories}")
        self.calories_label.pack(pady=5)

        self.protein_label = ctk.CTkLabel(self, text=f"Protein: {self.totalProtein}")
        self.protein_label.pack(pady=5)

        self.carbs_label = ctk.CTkLabel(self, text=f"Carbs: {self.totalCarbs}")
        self.carbs_label.pack(pady=5)

        self.fats_label = ctk.CTkLabel(self, text=f"Fats: {self.totalFats}")
        self.fats_label.pack(pady=5)

        self.breakfast_button = ctk.CTkButton(self, text="Generate Breakfast", command=self.generate_breakfast)
        self.breakfast_button.pack(pady=20)

        self.result_text = tkhtmlview.HTMLLabel(self, html="", width=375, height=400, background="black", foreground="white")
        self.result_text.pack(pady=20)

    def generate_breakfast(self):
        prompt = prompts.generate_breakfast(
            self.totalCalories, self.totalProtein, self.totalCarbs, self.totalFats
        )
        response = openai.chat.completions.create(
            model=model,
            messages=[
                {"role": "system", "content": "You are a dietitian assistant."},
                {"role": "user", "content": prompt}
            ],
            temperature=temperature,
            max_tokens=max_tokens
        )

        breakfast = response.choices[0].message.content
        breakfast = breakfast.replace("```html", "").replace("```", "")
        self.result_text.set_html(f"<div style='color: white;'>{breakfast}</div>")

if __name__ == "__main__":
    app = MealPlannerApp()
    app.mainloop()