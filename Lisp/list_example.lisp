(setf enemies '(troll wumpus ogre))
(setf friends '(jane sally roy))

(defun makepeace (name)
	(setf enemies (remove name enemies))
	(setf friends (cons name friends))
)

