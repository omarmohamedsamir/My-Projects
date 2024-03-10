# File: CS112_A1_T2_3_20231115
# Purpose: Two players subtract perfect square numbers from a pile of coins; initial coins chosen by user or generated randomly. Players input valid perfect square numbers; game continues until a player subtracts the last coin and wins.
# Author: Omar Mohamed Samir Soliman
# ID: 20231115
import random
def get_positive_integer(prompt):
    while True:
        try:
            # Get user input as an integer
            value = int(input(prompt))
            # Check if the input is a positive integer
            if value <= 0:
                print("Invalid input. Please enter a positive integer.")
            else:
                return value
        except ValueError:
            # Handle the case where the input is not a valid integer
            print("Invalid input. Please enter a valid integer.")
def is_perfect_square(n):
    # Check if a number is a perfect square
    root = int(n**0.5)
    return root*root == n
def main():
    #Welcome message
    print("Welcome to  Subtract a square game")
    # Infinite loop to keep asking for user input until a valid choice is made
    while True:
        # Get user input and convert it to lowercase for case-insensitive comparison
        choice = input("Do you want to choose the number of coins? (yes/no):").lower()
        if choice == 'yes':
            # If the user chooses 'yes', ask for the initial number of coins
            n_coins = get_positive_integer("Enter the initial number of coins:")
            break  # Exit the loop if a valid choice is made    
        elif choice == 'no':
            # If the user chooses 'no', generate a random number of coins
            n_coins = random.randint(10, 1000)
            # Ensure the generated number is not a square number
            while is_perfect_square(n_coins):
                n_coins -= 1
            print(f"The number of coins generated is {n_coins}")
            break   # Exit the loop if a valid choice is made     
        else:
            # If the user enters an invalid choice, print an error message
            print("invalIid choice. Please enter 'yes' or 'no'.") 
    # Game playing       
    while n_coins >= 1:
        # Player 1's turn
        move = get_positive_integer("Player 1: please enter the perfect square number you want to subtract:")
        # Validate the move
        while not is_perfect_square(move) or move > n_coins:
            move = get_positive_integer("Player 1: please enter a valid perfect square number to subtract:")
        # Update the number of coins after Player 1's move
        n_coins -= move
        print(f'Now we have {n_coins}') 
        # Check if Player 1 is the winner
        if n_coins == 0:
            print("Player 1 is the winner")
            break

        # Player 2's turn
        move = get_positive_integer("Player 2: please enter the perfect square number you want to subtract:")
        # Validate the move
        while not is_perfect_square(move) or move > n_coins:
            move = get_positive_integer("Player 2: please enter a valid perfect square number to subtract:")
        # Update the number of coins after Player 2's move
        n_coins -= move
        print(f'Now we have {n_coins}')
        # Check if Player 2 is the winner
        if n_coins == 0:
            print("Player 2 is the winner")
            break
# Call the main function when the script is executed
main()