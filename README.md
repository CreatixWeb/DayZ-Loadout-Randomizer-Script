# DayZ Custom Loadout Script

This **DayZ Custom Loadout Script** enhances gameplay with dynamic weather, economy settings, and customizable, role-based loadouts tailored by character class (e.g., nurse, soldier, prisoner, farmer). Each class has unique gear—for instance, the nurse has extensive medical supplies but limited cold protection, while the soldier is equipped with strong weapons and cold-resistant clothing but fewer medical items. This setup provides a strategic and immersive survival experience. No additional keys or mod files are needed; this script simply overwrites the basic `init.c` file, making it easy to implement. Ideal for server admins and mod developers, the script is fully extendable for further customization. For More Infos read below.

## Overview

This **DayZ Custom Loadout Script** initializes dynamic weather, in-game economy settings, and custom player loadouts based on character type. It offers random loadout options tailored for male and female characters, ensuring a unique experience for each player spawn. This script is designed to enhance realism and immersion in DayZ by introducing variability in items, health, and environmental conditions. 

**Ideal for:** Server administrators, mod developers, or players seeking a deeper, customized DayZ experience.

## Features

### 1. **Dynamic Weather Initialization**
   - **Overcast**: Sets a random overcast range between 40-60%.
   - **Rain**: Disabled by default.
   - **Fog**: Slight fog with randomized levels between 5-10%.
   - Weather settings can be modified to use different weather control methods for a more realistic in-game climate.

### 2. **Economy Initialization**
   - Initializes DayZ’s in-game economy by creating a "Hive" object in offline mode. This ensures that loot spawns, resources, and other economy-related elements are pre-configured.
   
### 3. **In-Game Date Management**
   - Sets the date to a specific day if it falls outside of a specified range, which helps manage seasonal or time-sensitive gameplay mechanics.

### 4. **Customizable Loadout System**
   - **Health Randomization**: Every item has randomized health, creating variability in item condition at each spawn.
   - **Gender-Based Loadouts**: Distinct loadouts for male and female characters, each with random selections from predefined arrays.
   - **Food, Drink, and Accessories**: Each loadout includes food, drink, and accessories tailored to survival needs. 

### 5. **Extendable Loadout Classes**
   - The loadout system can be extended by adding additional classes. Simply copy and modify an existing class, update the item arrays, and add the new class to the correct section in the code. (Reference in row 1157 for placement).

## File Breakdown

### Script Files
- `init.c`: Contains the main script, weather, economy setup, and loadout configuration.

## Detailed Loadout Breakdown

The loadout script includes functions to manage player inventories effectively and allow randomization for a unique experience:

1. **Set Random Health**:
   - Adjusts the health of each item in the loadout with values between 45% and 65%.
   
2. **Create Character**:
   - Generates a player entity with identity and position data, assigning a gender-specific loadout.

3. **Add Magazines (`addMags`)**:
   - Adds a specified type and quantity of magazines (or other items) to a player’s inventory. This function also configures the item for quick bar access.

4. **Male Loadout (`randomMaleClass`)**:
   - Randomized options for male players, including:
     - **Food**: Variety of canned goods, fruits, and vegetables.
     - **Drinks**: Includes soda types and water bottles.
     - **Clothes**: Randomly assigned Clothes for distinct player appearances.
   
5. **Female Loadout (`randomFemaleClass`)**:
   - Similar to the male loadout but with different accessory options, ensuring visual and functional variety across character types.

## Installation

1. **Upload the Script**: Replace `init.c` into the appropriate directory on your DayZ server (`mpmissions/yourmission/init.c`).
2. **Change the Respawn Dialogue**: Change the settings for the Respawn Dialogue to false. (otherwise the randomizer will only work if u click on "Random Character". Otherwise u will respawn with the old Character u already had.)
3. **Restart the Server**: After placing the script, restart the server to load the new configurations.
4. **Test**: Join the server to test the custom weather, economy settings, and loadout. (U need to use the Emote F10 or just run into a horde of Zombies ^^)

## Customization

- **Adjust Weather Settings**: Modify overcast, rain, and fog settings in the weather section to create unique weather conditions.
- **Add or Modify Loadouts**: To create a new loadout, copy an existing loadout class, update the arrays with new items, and add it to the correct section (line 1157) in the code. Ensure any new items are compatible with the DayZ environment.
- **Modify Date Logic**: If the reset month or day needs adjusting, you can customize the date variables to fit your server's desired season or time frame.

## Example Usage

To add additional food items to the male loadout, update the `foodArray` within `randomMaleClass`:
```cpp
ref TStringArray foodArray = {"Apple", "Peach", "PumpkinSlice", "TunaCan", "Rice"};
```
To create a unique set of female-only clothing options, you could modify the hat array within the female class to include custom hats or accessories.

## Contributing

If you'd like to suggest improvements, feel free to open an issue or fork the repository.

## License
You are free to use, modify, and distribute it, but please give credit to the original author.
