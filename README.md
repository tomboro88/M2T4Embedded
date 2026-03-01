# M2T4Embedded
UML Model to text transformation templates for embedded systems programming in C. 

*Work in progress...*

M2T4Embedded is a tool for automated generation of C code for embedded systems from UML state machine diagrams created in Papyrus. It leverages custom Acceleo (MTL) templates to streamline development of reliable embedded software.

## Motivation
This project originated from a willingness to speed up manual typing of state machines repeatable code in embedded systems. I observed that many embedded designs follow a common pattern—read sensors, calculate results, update outputs—resembling a PLC (Programmable Logic Controller) architecture. By consolidating proven code snippets into a tool, M2T4Embedded enables developers to design software at a higher level of abstraction using graphical UML diagrams. This approach shifts focus from low-level C programming to application-level design, improving efficiency and reliability in embedded development.

## Features
- Converts UML state machines and state diagrams to C code (enums, switch statements).
- Uses fully authored Acceleo (MTL) templates for code generation.
- Supports Eclipse Papyrus UML projects.
- Allows various class property types, array members, literal constants.
- Supports polymorphism with virtual functions.
- Supports state entry, exit and transition effect behaviors.
- Supports internal, external and local transitions.
- At the current stage supports nested states, orthogonal regions, choice pseudostates and junction pseudostates.
- Independent of external libraries. The target is to be usable both in bare metal and RTOS based projects.
- Comments attached to the model elements appear in the generated code.
- Code formatting follows Barr Group Embedded Coding Standard.
- Automated documentation for low-level code primitives.
- Contains test diagrams for validation of generated code.
- Doesn't use any framework nor runtime library, the transitions are hardcoded and strictly follow the state diagrams.
- Contains expected code for the provided test diagrams, that can be compared with the generated code.
- Status: Work in progress...

## Installation
- **Requirements**: Technically it is only Acceleo project containing *.mtl template files, which can be used with Eclipse Papyrus to generate code from Papyrus UML models. 
  - To open and use the project, Eclipse Papyrus version 2024-06 (the Papyrus Classic version, the latest Desktop (Sirius based) version is not tested yet) is needed. 
  - Acceleo version 3.7 can be installed from Eclipse Marketplace available in Papyrus.
  - c_test_expected project with units tests requires CMake and cmake4eclipse plugin. cmake4eclipse 5.1.0 can be installed from Eclipse Marketplace in Papyrus .
  - Optionally for validation of generated vs expected code I recommend to use git and Meld - automated Launch Configurations are provided with the project.
- **Opening**: Create Eclipse Workspace directory in a convenient place - outside the project's repository folder. Start Papyrus and point it to this directory. Then select File>Import>Git>Projects. 
TIP: In order to make the entry, exit, effect and guard behaviors visible directly on the state diagram, go to Window>Preferences>Papyrus>Diagrams>PapyrusUMLStateMachineDiagram>Transition and behavior options, and set the "Shown number of lines for opaque expressions/behaviors" to 3.
- **Code generation**: Look at the **Launch Configurations** section below.
- **Running unit tests**: CMake and cmake4eclipse plugin are required for c_test_expected project build. **Test Expected** Run configuration starts the tests.

## Repository structure
- **c_expected** Eclipse C Project with the reference desired output. Each package in the UML model is expected to give a pair of corresponding *.c and *.h files which can contain a number of classes - depending on the contents of the package.
- **c_generated** Eclipse C Project with the generated actual output C source code.
- **c_test_expected** Project for unit tests for the expected output code.
- **LaunchConfigurations** A folder with Eclipse Launch configuration files for Eclipse. By default these files are stored in Eclipse Workspace folder, but can be configured to be saved in another directory. In this particular case - they are stored here, so that they can be versioned by git and reused by other users cloning the repository. They will be imported automatically by Eclipse Papyrus when the complete repository will be opened by File>Import>Git>Projects from Git menu command in the main menu. There are the following Run configurations:
  - **Generate** Runs Acceleo to generate the code from the included test diagrams to the c_ecpected/src directory.
  - **Generate Code and Verify with Meld** Generates the code and launches git and Meld programs to make the comparison between the generated and expected output files. Uses bash commands to run Meld and git and tested at Ubuntu 22.04. For Windows the command must be changed in the Run>External tools>External tools configuration menu.
  - **Generate Code and Verify with Git** Generates the code and launches git to make a quick comparison between the generated and expected output files. In practice this is the most frequently used one, once you already have your Meld program opened. Git creates a short comparison status report and saves it in diff_report.txt file at the root of the git repository. Uses bash command similarly to the above.
  - **Compare with Git** Runs the git command for generated code comparison to the expected output.
  - **Compare with Git and Meld Folder** Runs the git and Meld commands for generated code comparison to the expected output. Eclipse Papyrus expects that you select some of the projects in the workspace, otherwise it will give a message that no resource was selected.
  - **Test Expected** Runs the c_test_expected project containing unit tests for the expected code modules.
  - **c_expected** Runs the compiled c_expected project.
- **tbo.acceleo.psm.uml.gen.c** The acceleo project used for code generation. It contains a **default.properties** file which can control some options related to the code generation:
  - **include_debug_markers** - By default set to false. Change to true to include additional comments in the generated code. They will provide information which pieces of the generator are responsible for each particular piece of output code. It greatly simplifies the further development of the generator.
  - **line_width** Sets the maximum number of characters in a single line of output code. The generator automatically formats the code to make it easy to read.
  - **indent_width** Sets the number of spaces used for code indentation.
- **testdiagrams** Eclipse Papyrus project with test uml diagrams for validation of the generated code. It contains 4 diagrams at the moment:
  - **TransitionKindTestDiagram** Used for testing different kinds of transitions: internal, external and local, nested statesand orthogonal regions.
  - **JunctionTestDiagram** Represents different combinations of transitions utilising Junction pseudostate. Still work in progress.
  - **NewPackageDiagram** It has practically no use at the moment, but stays here, since your models can contain all kinds of UML diagrams - only the elements recognised by the generator will be used for code generation.
  - **NewClassDiagram** Illustrates how class diagrams can be easily used to visualise the structure of your code and add properties and member functions to your classes.

## Usage
Launch configurations are stored in the LaunchConfigurations project in LaunchConfigurations folder. They will be imported automatically into Eclipse when all projects in the git repository will be imported by File>Import>Git>Projects from Git, and selecting Import existing Eclipse projects in the Wizard.

The default included Acceleo Launch Configuration uses the test diagrams as uml model source. To generate code from your custom model create a new Run Configuration from Run> Run Configurations and double click Acceleo Application, or clone the existing configuration called Generate. In the new configuration choose your model .uml file and target directory for generated code. The selected Runner should be Acceleo Plug-in Application. Choosing Java application requires the setting of additional paths mappings, which are not configured now. Then you can click the Run button.

Git only comparison can be executed from Run>External tools>Compare with Git. This will generate diff_report.txt at the root folder of the git repository.

Additional visual comparison with the Meld tool can be executed from Run>External tools>Compare with Git and Meld Folder.

Note: Git- and Meld-based Launch configurations were tested on Ubuntu 22.04. If using Windows you will need to edit or duplicate them and change git and Meld executable paths and bash commands. 

There are also Launch Groups which start the comparisons automatically after Acceleo code generation is completed. They are called "Generate Code and Verify with Meld" and "Generate Code and Verify with Git". Two of them are created since when running the Meld comparison, a new Meld window is opened each time. It turns out to be convenient having the Meld window opened all the time, thus after opening the Meld comparison you can keep it opened and use only git comparison the next time and just refresh the Meld window when needed.
### Note
The generator also performs code formatting which relies on the proper configuration of line endings in the generator template files. It was working well both on Windows (CRLF) and Linux (LF) assuming proper configuration of git and Eclipse Papyrus. Now .gitattributes file is added to maintain consistent line endings in the repository. Please make sure that your git settings reflect the settings used by your Eclipse Papyrus. The recommended settings are:
- **Windows**: 
  - git config --global core.autocrlf true
  - Eclipse Papyrus: Window>Preferences>General>Workspace>New text file line delimiter: Windows
- **Linux**: 
  - git config --global core.autocrlf input
  - Eclipse Papyrus: Window>Preferences>General>Workspace>New text file line delimiter: Unix

## Further Development Plans
- Add unit tests for the expected code project. Then the tested expected code will be a reliable reference for the generated code.
- Add custom UML profile that will enhance the possibilities to control the generated code primitives.
- Implement event queue handling after cleaning up the generated code. A working prototype of event loop bare-metal as well as Freertos based code generation already exists in Python language with Jinja2 templates. Then the currently supported features are enough to implement real life applications.
- Add documentation how to use the generator with a simple PLC pattern that could be a basis for many reliable embedded control system designs.
- Add documentation with tips how to combine UML modeling and code generation with BDD (Behavior-Driven-Development).
- Real life example project: a file system for flash memory resilient to power failures, generated from UML state machines - partially implemented manually already - waiting for automated code generator.
- Real life examples for embedded platforms.
- Advanced pseudostates: history, fork, join, entry points, exit points, submachine states.
- C++ version - The hardest part of the generator are queries traversing through the model. They already exist for C. Migration to C++ can reuse them.

## License
MIT License. The MTL templates, UML diagrams and expected *.c and *.h source files are fully authored by @tomboro88. 


**Papyrus** and **Acceleo** (both EPL 2.0) are used **only as offline development and code-generation tools** and are **not distributed** with this project. The generated code is not a derivative work of Papyrus/Acceleo and carries no EPL-2.0 obligations.

Unit tests use **Unity** framework (MIT).
