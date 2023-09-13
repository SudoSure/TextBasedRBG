
# A Text-Based Role-Playing Game (RPG)
 
>  Authors: \<[Jinseok Lee](https://github.com/Jinseok1st)\> \<[Aris Chen](https://github.com/achen169)\> \<[Hao Feng](https://github.com/hfeng95)\> \<[Trevan Nguyen](https://github.com/TrevNg)\>
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory or Visitor
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * Each member of the group must actively participate in the Github Project board and reviewing commited code.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold one check-in meeting with your lab TA in addition to the final demo.

## Project Description
> Our Project is a Text-Based RPG Game. We have chosen this concept as our final project because our group have all had experienced fond memories of playing RPG games in our younger years and were heavily interested in partaking in the creation of one of our own. The ability to incoporate our own creative ideas into implementation of game mechanics, story-telling, and character progression are amongst the many reasons that this project idea is important and interesting to us. We will construct this program through the use of the C++ Programming language as well as the Github hosting service to manage our repositories and allow us to work together smoothly and efficiently. Users will be able to input through a text-based interface where text-prompts and options will displayed on screen for users to select. This project will allow users to choose from multiple character classes, buy and sell items, fight or flee, use skills, and access a personal inventory.

 > ## Phase II
 > Epic for each feature.
1) Inventory(Shop)
    Epic :
          User can use inventory anytime user want. 
          User can stroing the items, using items, buying and selling items at the shop. 
          User can see certain items in the inventory. 
    
    Design pattern: Composition pattern

2) Choosing Class
    Epic:User should be prompted to choose class at beginning of game.
         User should be presented with list of available classes to choose from.
         User should be able to select a class by entering its numeric value.
         Each class should be instantiated with unique skillset and stats
    
    Design pattern: Strategy pattern
    
3) Fight or Flee(Combat)
    Epic:
        User should be able to choose to fight or flee during a fight sequence. 
        This will be prompted for every turn.
        
    Design pattern: Strategy pattern
    
4) Using skills(Combat)
    Epic:
        User can use skills during fight sequences. 
        Skills will depend on the class of the character.

    Design pattern: Strategy pattern
    
5) Buy(shop)
    Epic: Users should be able to access their inventory to see what items they have. 
          Users should be able to access a general shop from the main menu and see what items they can buy.
          Users should be able to see their current balance of money.
    
    Design pattern: Composition pattern

6)  UI
    Epic: Users should be able to see possible actions at home base
          Users should be able to see possible actions whilst fighting
          
    Design pattern: Strategy pattern
 
## Class Diagram
https://lucid.app/lucidchart/db8c5062-4717-4560-a3ec-2c3058e595d8/edit?viewport_loc=3085%2C1457%2C2560%2C1168%2C0_0&invitationId=inv_c4f2ad28-15a9-4540-b2bd-f27f6bb8af47

UML Diagram Description:
There are three main parts to our project. We use a composite design pattern for our inventory system which includes player and shop objects, and a strategy pattern for our entity and interface systems. The player classes and monsters are inherited from the Entity parent class, which has the name, max health and mana, and stats attributes. The user can choose from three different player classes: knight, mage, and archer, each with its own set of skills and stats. There are four variations of monsters: easy, normal, hard, and boss, also each with its own set of stats. In terms of user interface, our project operates using a CurrentState object, which determines the menu and options which are displayed onscreen at any given time. We have four menus: main, combat, class selection, and shop. The main menu is the default screen which is displayed when not in combat or in shop. The combat menu is displayed during combat and offers various combat-related options to the user. The class selection menu is displayed at the beginning of the game, and prompts the user to select from the available player classes. The shop menu is displayed when the user chooses to interact with the shop, and is where the user can buy or sell items.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II.

https://lucid.app/lucidchart/db8c5062-4717-4560-a3ec-2c3058e595d8/edit?viewport_loc=3085%2C1457%2C2560%2C1168%2C0_0&invitationId=inv_c4f2ad28-15a9-4540-b2bd-f27f6bb8af47

Two design patterns we choose are strategy pattern and compoiste pattern.
For composite pattern, it lets clients treat individual objects and compositions of objects uniformly. For example, objects compose a whole unique object and we might want to apply some operation on the whole object instead of the each of the individual objects. Because we have multiple item classes that inherit from the item base class; we have implemented a composite pattern so that each unique object can have its own specific operations and make it easier for us to easily and accurately access the objects we created in our code. This design pattern allows us to treat every item in the user's inventory the same, including collections of other items forming ItemStack objects, which are instances of a subclass of the Item class. As a result, our code for Item and the client's interaction with it can be simplified and straightforward.

We chose to implement the strategy design pattern as one of our design patterns for this project for its flexibility. One feature which we use this pattern for is the abstract PlayerClass class and its subclasses Knight, Mage, and Archer, because we want these classes to each have a different set of abilities but to be used the same way and we do not know which one will be chosen until the user chooses it. So, these three subclasses will share a common interface for their behaviors, embodied in the Class_Behavior interface, but the behaviors themselves will be defined by the individual concrete subclasses. This way, we reduce repetitive code and are able to only instantiate what is necessary during runtime, leading to higher efficiency in our code overall. 

 > * You should also update this README file by adding the following:
 >   * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
