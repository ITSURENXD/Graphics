# 🔧 Installation Instructions for 32-bit WinBGIm graphics library C++ on vscode
- WinBGIm (Windows Borland Graphics Interface) is designed for the installations with 32 bit C++ compilers on Windows Operating system. 

&nbsp;

# 📋 Requirements
- Windows Operating System
- 32-bit C++ Compiler (recommended installations procedures listed)
- Library and header files (3 files foud on this directory along this instruction)
- IDE (VSCode for being a common choice)

&nbsp;

# 🔧 Installations
- The following will list the procedures for the installations of requirements

    ## 32-bit TDM GCC Compiler (RECOMMMENDED) 
    - The steps for installation of the 32 bit TDM GCC compiler is as follows
    - ### ⬇️ Download the Compiler
        - Download the 32 bit version of the compiler from the [Website](https://jmeubank.github.io/tdm-gcc/download/)
        - <img src="./Resources/Screenshots/TDM GCC Download Links.png" alt="TDM GCC Web Directions" width=700px>
    - ### 🔧 Installations:
        - Execute the installer.
        - Click on the "Create" Option.
        - <img src="./Resources/Screenshots/TDM installation create option.png" alt="Create Option on Installer" width=400px>
        - Click on the "MinGW/TDM (32-bit)" (IMPORTANT)
        - <img src="./Resources/Screenshots/TDM installation 32bit option.png" alt="32 bit option on the Installer" width=400px>
        - Follow the default installation procedures for the rest of the steps otherwise you might have to change the environment variables.
        - <img src="./Resources/Screenshots/TDM installation on paths.png" alt="Installation path option on the Installer" width=400px>
    - ### ✅ Check Installation:
        - Open a terminal (Powershell/cmd) and type 
        ```pwsh
        gcc --version
        ```
        - <img src="./Resources/Screenshots/Gcc test Pass.png" alt="Gcc test pass" width=400px>
        - If it does not return unrecognized cmdlet, and shows information about the compiler, you are done with this step else follow the [Diagnosing Problems](#️-diagnosing-problems).
        - <img src="./Resources/Screenshots/Gcc Test Fail.png" alt="Gcc test fail" width=400px>

    - ### ⚠️ Diagnosing Problems
        - If the "gcc --version" returns an error you can try 
            - 1. #### Restarting the terminal
            - Often times, a terminal that if opened before the installation will return errors, restart all terminals if required.

            - 2. #### Environment Variables
            - One of the most common issues, when installing at a custom path instead of the default installation path from the setup to remedy this follow the below
                - Go to your installation directory. For those who have not changed the default installation path it will be:
                - 1. Get the Path for binaries
                    ```pwsh
                    cd C:/TDM-GCC-32/
                    ```
                    - Go to the "bin" directory
                    ```pwsh
                    cd bin
                    ```
                    - Get the path to this directory
                    ```pwsh
                    pwd
                    ```
                    - <img src="./Resources/Screenshots/bin path copy.png" width=400px>
                    - copy this path
                - 2. Copy the path to PATH variable in the enviroment:
                    - Search and open the "Environment Varibles" from Windows start
                    - Press the "edit environment Varibles" button to get the next window
                    - <img src="./Resources/Screenshots/Environment Variables Search.png" width=400px>
                    - Double click on the "PATH" in the user variables section on top
                    - <img src="./Resources/Screenshots/Environ Variables listing 1.png" width=400px>
                    - Click "New" and paste the Copied Path to the binaries
                    - <img src="./Resources/Screenshots/Environ Variables Listing 2.png" width=400px>
                    - Hit "Okay".
                    - <img src="./Resources/Screenshots/Adding a new path.png" width=400px>
                    - Restart Pre-Opened Terminals and try to use the command again.


    ## ⬇️ Download the Library and Header Files
    - On this github repo: Find the directory containing the files: [Directory](https://github.com/ITSURENXD/Graphics/tree/188e0ba5dc08816d7c0af8ce562d07073865f42b/C/Resource)
    - Download all three files
        - 1. graphics.h
        - 2. libbgi.a
        - 3. winbgim.h
    - <img src="./Resources/Screenshots/github repo files.png" width=400px>


    ## 🔧 Installing the Library and Header Files
    -  With the 3 files downloaded and the compiler installed. 
        - 1. Copy graphics.h and winbgim.h 
        - 2. Locate the **"include"** Directory on the installed directory. For those who have not used custom installation path:
        ```pwsh
        cd C:/TDM-GCC-32/include
        ```
        - 3. Pase the Files
        - 4. For the last file: libbgi.a, copy the file
        - 5. Then paste to the lib folder on the installed directory. For those who have not used custom installation path:
        ```pwsh
        cd C:/TDM-GCC-32/lib
        ```


    ## 🔧 Install the IDE: VSCode (RECOMMENDED)
    - Download and install VSCode following the instructions on their website.
    - Suggestion: Enable the auto save with delay option.

    - Congratulations, base installations are complete.

&nbsp;

# ⚙️ SETUPS
- Follow the following instructions to run the graphics from vscode
    ## ⚙️ VSCode Setups
    - Goto the Extensions tab on the left
    - Search for **"Code Runner"**.
    - Install it.
    - <img src="./Resources/Screenshots/Code runner installs.png" width=400px>

    ## ⚙️ Code Runner Setup
    - Once installed, go to the extension settings
    - ### Set up Run in Terminal
        - Search for "Run in Terminal" and check the box and save it.
        - <img src="./Resources/Screenshots/Run in terminal Code Runner.png" width=400px>
    - ### WinBGIm run setups
        - Search for "Executor Map" and press on the "Edit Settings.json" 
        - <img src="./Resources/Screenshots/executor map Code Runner.png" width=400px>
        - Once there, Look for the "cpp" on "code-runner.executorMap"
        - <img src="./Resources/Screenshots/find cpp in executor map code runner.png" width=400px>
        - Change the value to 
        ```
        "cd $dir && g++ $fileName -o $fileNameWithoutExt -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && $dir$fileNameWithoutExt"
        ```
        - <img src="./Resources/Screenshots/Value change executor map.png" width=400px>
        - You can Now run a graphics application that utilizes "graphics.h" by presseing "Ctrl+Alt+N" or 
        - By clicking the "Run Code" from the drop down menu of execution button.
        - <img src="./Resources/Screenshots/run program.png" width=400px>



