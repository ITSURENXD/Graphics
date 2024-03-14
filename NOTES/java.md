# Introduction
- creating using jframes
- was easier and more compatible to setup than the c project

## Setting up 
- setting up basic things
    ### Imports list of imports
    - List of all the imports:
    ```java
    import javax.swing.JFrame;
    ```

    ### Setting up a Visible screen
    - It is done with JFrame but visibility needs to be toggled.
    - Size of the window needs to be set or it becomes too small to see.
    - <span style="color:orange"> **Warning:**</span> The close button only hides the window and doesn't close it. reference the [Problem](#close-button-hiding-window)

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


## Problems
- List of all the problems that occured.
    ### close button hiding window
    - to fix this
    ```cpp
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    ```