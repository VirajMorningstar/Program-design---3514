'''============================================================================
Author Name  :- Viraj Amarasinghe
Prject Name  :- project1_furniture
Class        :- COP3514 Progrm Design
Date         :- 01/23/2022
Computer Engeineeering - University of South Florida. 
This programe calculate the monthly ental cost of furnitures
============================================================================'''

# import math library
def main():
    # Variable initialization
    furniture_cost = 0
    yearly_cost = 0
    amount = 0
    monthly_rental_cost = 0
    number_of_months = 0
    final_year = 0
    
    # The menu of the furniture to select
    
    print("Please Select from the following menu:")
    print("1. Sofa, 2 Loveseat, 3. Chair, 4. Dining Table, 5. Coffee Table, 6. End Table, 7. Quit")
    
    try:
        item_selected = int(input())
        
        
        