(Project: Polymorphic Screen Manager Using Shape Hierarchy) Develop a basic graphics package. 
Use the Shape hierarchy implemented in Exercise 13.13. Limit yourself to two-dimensional 
shapes such as squares, rectangles, triangles and circles. Interact with the user. 
Let the user specify the position, size, shape and fill characters to be used in drawing 
each shape. The user can specify more than one of the same shape. As you create each shape, 
place a Shape * pointer to each new Shape object into an array. Each Shape class should 
now have its own draw member function. Write a polymorphic screen manager that walks 
through the array, sending draw messages to each object in the array to form a screen 
image. Redraw the screen image each time the user specifies an additional shape.
