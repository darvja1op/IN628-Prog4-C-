#Ruby Assignment

#create Ruby Word collection. This is an empty array that will hold all of the words from our text file.
hangman_words = []

#create Ruby collection for holding individually guessed letters
guessed_letters = []

#read in words from file line by line. The extracted line is then 'pushed' into the array. Meaning the array will now hold that value.
#the syntax for this loop is very readable, as in "For each line in the file, do the following..."
File.foreach( 'hangmanWords.txt' ) do |line|
  hangman_words.push(line)
end

#print out contents of array
# hangman_words.each { |word| puts word }

#Ruby does not need semi-colons ';' to terminate lines of code.
#Ruby also does not need you to specify a data type.
#This paradigm makes Ruby very easy to learn, as you don't have to worry about which data type to use, the compiler handles that for you!
#setting boolean to run game loop
play_again = true


#setting countdown timer for guesses
max_num_guesses = 20

#the 'begin' keyword indicates the start of a programming structure.
#in this case it signifies the start of a do while loop, with the conditional statement at the end
begin
  num_guesses = 0
  game_win = false

  #the sample method selects a random word from a collection
  #the strip method removes any white spaces around the text
  #these methods can be accessed by using a full stop '.' after the object
  selected_word = hangman_words.sample.strip
  #split word into char array
  word_split = selected_word.split("")

  begin
    letter_score = 0
    #the puts key word prints a string (text) to the console window.
    #this allows the user to see what is going on behind the scenes, and can also prompt the user for input.
    puts "Guesses left: " + (max_num_guesses - num_guesses).to_s # the '.to_s' call simply gets the string equivalent of the number
    puts "Enter a letter to guess:"
    #the gets method reads in user input from the console.
    #the '.chomp' strips a line break from the end of the text
    guessed_letter = gets.chomp

    #this simple while loop keeps running until the user enters a letter that hasn't already been used.
    #the '.include?' on the guessed_letters array simply checks if an argument (guessed_letter) occurs in the array.
    while guessed_letters.include? guessed_letter
      puts "You've already used that letter!"
      puts "Enter a letter to guess:"
      guessed_letter = gets.chomp
    end

    #this line adds the guessed letter to the guessed_letters array, while keeping the existing letters untouched.
    guessed_letters.push(guessed_letter)

    #prints all the guessed letters to the console so the user can tell what letters have been used.
    puts "Guessed Letters: "
    guessed_letters.each { |c| print c + " " } # a concise way of iterating through each element and printing to the console
    puts ""

    # '.each_char' iterates through each character of a word. Each character inside the loop is referenced by 'c'
    selected_word.each_char do |c|
      #if the letter has been guessed, print it to the console.
      #the 'or' keyword implies that if the letter has not been guessed, then print a placeholder '_ '
      print c if guessed_letters.include? c or print '_ '

      #a shorthand if then statement.
      #if guessed letter is equal to the character in the word, then increase letter_score by 1
      letter_score += 1 if guessed_letter == c
    end # marks the end of the each char loop

    #the if statement tests if the letter score is equal to the words length
    #if this is true, then the user has successfully guessed the word
    if letter_score == selected_word.length
      game_win = true #word guessed correctly
    end # marks the end of the previous if statement

    puts "" # puts a new line to the screen for readablility

    #this statement increments the object 'num_guesses' by one.
    #it can be read as num_guesses is set to itself plus one.
    num_guesses += 1
    puts "Score: "+letter_score.to_s # prints the letter score (number of correct guesses) to the screen

    #the end keyword marks the finish of a structure.
    #this one indicates the end of the do while loop, with the while loop condition coming after.
    #the '&&' means 'and', this can be read as "While the user hasn't won the game, AND while the user hasn't '!=' exceeded the maximum number of guess, run the loop."
  end while game_win == false && num_guesses != max_num_guesses

  #depending on if the user guessed the word or ran out of guesses, prints the outcome of the game (win/lose) to the screen
  puts "Congratulations you guessed the word: "+selected_word if game_win or puts "You took too many guesses. The Man was hanged. The word was: "+selected_word

  #the following code block is how we end the game or allow the user to play another round.
  #when asking the user if they want to play again it is important that you specify how they should respond.
  #this is because the user may enter 'yes', while you drive your game loop based on 'y' or 'n'
  puts "Do you wish to play again? y/n"
  user_input = gets.chomp
  if user_input == 'y'
    play_again = true
    # the elsif (else if) tests another condition without the need to end the previous if and start another if statement
  elsif user_input == 'n'
    play_again=  false
  end # end of the if and elsif

end while play_again # run the game loop while the user wishes to play again.