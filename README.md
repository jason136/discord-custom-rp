# HOW TO USE:

To get the custom rich presence client working, you're going to have to start by making a discord application. 

1. Firstly, go to the [Discord Developer Dashboard](https://discord.com/developers/applications) and press New Application in the top right. 

2. Give the application a name (this is what Discord will say you are "playing"). Don't worry about this too much, it can always be changed. 

3. Once on this page find the APPLICATION ID under general information, copy it and input it to the GUI after pressing the input Client ID button. 

4. Go back to the developer dashboard and click on Rich Presence -> Art Assets

5. Here, upload any images you want to have show up on your rich presence status. 

6. Finally, return to Discord Custom Rich Presencee Client and press update presence. 

7. Input all relevant information and when you press OK it should now show up as your Discord status. 

## Helpful Notes:

* The visualizer on the developer dashboard is very helpful in rendering what the status will look like on Discord. It's a good idea to create the status there and then copy the fields into the Client. Make sure the image keys are exact. 

* Art assets are checked by Discord (for nsfw I think) and will not show up immediately after uploading. Wait a couple minutes and refresh the page. 

* Discord rich presence can only be updated once every 15 seconds, updating too quickly will cause a backup. 

* If the rich presence is not showing up, best practice is to close the application, delete "config.txt", reopen, and make sure the Client ID is inputed correctly. 

* The application will create a "config.txt" file in which your inputs are stored. As long as the executable and text file are in the same directory, the application will automatically read and use these settings when it's opened. The config file is not meant to be edited except by the application and doing so could cause problems. 
