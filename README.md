# Wumpus
2D game built as polymorphism and overall OOP practice,with a variety of features including a debug mode


Hunt the Wumpus is a game set inside the cave of the Wumpus, a scary, gold-hoarding monster
who likes to eat people who disturb its sleep. The player's goal is to guide an adventurer to
either kill the Wumpus, or find its hidden gold and escape alive. The Wumpus lives in a large
cave of rooms arranged in a grid, where each room has four tunnels leading to the rooms to the
north, east, south, and west.

The adventurer starts the game in a random empty room in the Wumpus’ cave. Their starting
position is also the location of the escape rope that they must use to escape after they’ve
completed their task.

Each room may be empty, or it may contain one (and only one) of four "events" (all described
below): two kinds of dangerous hazards, the terrifying Wumpus, and the gold treasure. When
the adventurer is in a room that’s adjacent to one containing an "event", the player will receive a
percept (a message) to inform them about the event the adventurer is close to.

The player wins the game if they can safely guide the adventurer through the cave to either a)
kill the Wumpus, or b) pick up the gold and make it back to the escape rope unharmed!

