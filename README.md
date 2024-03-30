# ObjectARX Basic Operations

## Overview
ObjectARX is a programming environment that allows developers to create custom AutoCAD applications using C++. This README provides a guide to basic operations in ObjectARX, including creating a project, writing custom commands, drawing lines with predefined coordinates, adding layers, drawing lines using user input, and changing the color of selected objects.

## Prerequisites
To work with ObjectARX, you need the following:
- AutoCAD software installed on your machine.
- ObjectARX SDK installed and configured for your development environment.
- Basic knowledge of C++ programming language.

## Getting Started
Follow these steps to get started with ObjectARX:

1. Install AutoCAD on your machine.
2. Download and install the ObjectARX SDK compatible with your AutoCAD version.
3. Set up your development environment (e.g., Visual Studio) to work with ObjectARX.
4. Create a new ObjectARX project or open an existing one.

## Creating a Project
To create a new ObjectARX project:
1. Open your development environment (e.g., Visual Studio).
2. Create a new C++ project.
3. Configure project settings to include ObjectARX SDK and necessary dependencies.
4. Write your custom commands and functionality using ObjectARX APIs.

## Writing Custom Commands
ObjectARX allows you to define custom commands that extend AutoCAD's functionality. To write a custom command:
1. Define a new command class inheriting from the AcRxCommand class.
2. Implement the command logic in the command's main() method.
3. Register the command using the acedRegCmds macro.

## Drawing a Line with Predefined Coordinates
To draw a line with predefined coordinates:
1. Use the AcDbLine class to create a new line object.
2. Set the start and end points of the line using the setStartPoint() and setEndPoint() methods.
3. Add the line object to the AutoCAD database using the appendAcDbEntity() method.

## Adding a Layer
To add a layer:
1. Create a new layer using the AcDbLayerTableRecord class.
2. Set the properties of the layer (e.g., color, line type) using setter methods.
3. Add the layer to the layer table using the appendAcDbObject() method.

## Drawing a Line Using User Input
To draw a line using user input:
1. Prompt the user to enter the coordinates of the start and end points.
2. Use the entered coordinates to create and draw a line object.

## Changing Color of Selected Objects
To change the color of selected objects:
1. Iterate through the selected objects in the AutoCAD database.
2. Set the color property of each selected object to the desired color.

## Acknowledgments
- AutoCAD and ObjectARX communities for providing documentation and resources.
