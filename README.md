## Playlist Management System

#Description: The Playlist Management System is a C++ program that uses a doubly linked list to manage a list of songs. Each song is uniquely identified by an ID and has associated information such as the title and artist. The system allows users to perform the following operations:

## Design view 
![image](https://github.com/user-attachments/assets/cfc0b44a-ea61-455a-bd83-8ec595b2e7bf)


## Add a new song to the playlist.
Remove a song from the playlist by its ID.
Display the entire playlist in the order songs were added.
Display the playlist in reverse order.
Search for a song by its ID.
Exit the program.
Approach Used:

Doubly Linked List: The playlist is implemented using a doubly linked list, where each node represents a song. Each node contains:

songID: A unique integer identifying the song.
title: The title of the song.
artist: The artist of the song.
Pointers to the next and previous nodes, allowing traversal in both directions.
Class Structure:

Node: Represents a single song in the playlist.
Playlist: Manages the operations on the playlist such as adding, removing, displaying, and searching for songs.
User Interaction: The main function provides a menu-driven interface allowing the user to interact with the playlist by choosing various operations.

## Error Handling:

The program checks for duplicate song IDs when adding a new song and prompts the user to enter a unique ID if a duplicate is found.
It handles cases where songs are not found during search or removal operations
