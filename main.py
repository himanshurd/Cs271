class CruiseTime:

  #Using name variable globally because I'm using this variable more than in one function. 
name = ""

def welcome(self):
  print("Welcome to the Solar System")
  print("There are 9 planets to explore")

def enter_name(self):
  global name
  name = input("Enter your name: ")
  print("Nice to meet you, "+name+"."+" My name is Eliza, I'm an old friend of Alexa")
  print("Lets go on an Adventure!")

def choose_planet(self):
  random = False
  ask = input("Shall I randomly choose a planet fr you to visit (Y or N) ")
  if (ask == "Y"):
    random = True
    print("Travelling to Mars...")
    print("Arrived at Mars. It is hotter than the earth and air is not pure at all")
  elif (ask == "N"): 
    global name
    name = input("Name the planet you want to visit? ")
    print("Travelling to "+name+"...")
    print("Arrived at "+name+". I'm happy that i'm visiting this planet.")
  else:
    choose_planet()
    
   # def welcome_user(self):
    #    print("Welcome to the Solar System!")
     #   print("There are 8 planets to explore.")
    
    #def prompt_users_name(self):
     #   name = input("What is your name? ")
      #  print("Nice to meet you, " + name +". My name is Eliza, I'm an old friend of Siri")
       # print("Let's go on an adventure!")

    #def prompt_random_planet_choice(self):
     #   random_decision = input("Shall I randomly choose a planet for you to visit? (Y or N) ").casefold()
      #  if (random_decision == "Y".casefold()):
        #    return True
       # elif (random_decision == "N".casefold()):
         #   return False
        #else:
          #  self.prompt_random_planet_choice()

    #def prompt_planet_name(self):
       # return input("Name the planet you would like to visit. ")

    def unknown_planet(self, planet):
        if (planet == None): 
            return print("Looks like this planet doesn't exist!")
        print("Traveling to " + planet.get_name() + "...")
        print("Arrived at " + planet.get_name() + ". " + planet.get_description())