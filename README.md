The launch configurations are stored in the LaunchConfigurations project in LaunchConfigurations folder. They will be imported automatically into Eclipse when all projects in the git repository will be imported by File>Import>Git>Projects from Git, and selecting Import existing Eclipse projects in the Wizard.

Git only comparison can be executed from Run>External tools>Compare with Git. This will generate diff_report.txt at the root folder of the git repository.

Additional visual comparison with the Meld tool can be executed from Run>External tools>Compare with Git and Meld Folder.

There are also Launch Groups which start the comparisons automatically after Acceleo code generation is completed. They are called "Generate Code and Verify with Meld" and "Generate Code and Verify with Git". Two of them are created since when running the Meld comparison, a new Meld window is opened each time. It turns out to be convenient having the Meld window opened all the time, thus after opening the Meld comparison you can keep it opened and use only git comparison the next time and just refresh the Meld window when needed.
