# Introduction
- creating using jframes
- was easier and more compatible to setup than the c project

## Setting up 
- setting up basic things
    ### Imports list of imports
    - List of all the imports:
    ```java
    import javax.swing.ImageIcon; //for image icon
    import javax.swing.JFrame;
    ```

    ### Setting up a Visible screen
    - It is done with JFrame but visibility needs to be toggled.
    - Size of the window needs to be set or it becomes too small to see.
    - <span style="color:orange"> **WARNING:**</span> The close button only hides the window and doesn't close it. reference the [Problem](#close-button-hiding-window)
    - <span style="color:orange"> **WARNING:**</span> The Window is resizable. reference the [Problem](#make-window-unresizable)

    ```java
    public class test {
        public static void main(String[] args){
            JFrame frame= new JFrame(); //create a frame
            frame.setSize(800,800);
            frame.setVisible(true);//making it visible
        }
    }
    ```

    ### Giving Title to Window
    - Done with setTitle method
    ```cpp
    frame.setTitle("GUI TEST");
    ```

    ### Giving Icon to the window [🔧Needs Work]
    - Done with ImageIcon
    - Need to [import](#imports-list-of-imports)
    - <span style="color:red"> **PROBLEM:**</span> Did not work on Fedora Linux. reference the [Problem](#imageicon-not-working-linux)
    ```java
    ImageIcon image = new ImageIcon("../NOTES/Resources/icon.png");
    frame.setIconImage(image.getImage());
    ```

    ### Setting Background of the Window
    - needs to be chained
    ```cpp
    frame.getContentPane().setBackground(Color.BLACK);
    ```
    - for custom colors
    ```cpp
    frame.getContentPane().setBackground(new Color(131,139,167));
    ```



## Problems
- List of all the problems that occured.
    ## Solved
    - List of solved problems
        ### close button hiding window
        - to fix this
        ```cpp
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ```

        ### Make window Unresizable
        ```cpp
        frame.setResizable(false);
        ```
    
    ## To be solved
    - List of problems to be solved
        ### ImageIcon not working linux
        - //todo