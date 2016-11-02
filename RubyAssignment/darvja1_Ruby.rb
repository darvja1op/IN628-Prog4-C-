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
#This paradigm makes Ruby very easy to learn, as you don't have to worry about which data type to use, the Compiler handles that for you!
#setting boolean to run game loop
play_again = true


#setting countdown timer for guesses
max_num_guesses = 20


begin
  num_guesses = 0
  letter_score = 0
  game_win = false

  #select random word from collection
  selected_word = hangman_words.sample
  #split word into char array
  word_split = selected_word.split("")

  begin
    puts "Guesses left: " + (max_num_guesses - num_guesses).to_s
    puts "Enter a letter to guess:"
    guessed_letter = gets.chomp

    while guessed_letters.include? guessed_letter
      puts "You've already used that letter!"
      puts "Enter a letter to guess:"
      guessed_letter = gets.chomp
    end

    guessed_letters.push(guessed_letter)
    puts "Guessed Letters: "
    guessed_letters.each { |c| print c + " " }
    puts ""

    selected_word.each_char do |c|
      print c if guessed_letters.include? c or print '_ '
      letter_score += 1 if guessed_letter == c
    end

    if letter_score == selected_word.length
      #word guessed correctly
      game_win = true
    end

    num_guesses += 1
    puts "Score: "+letter_score.to_s

  end while game_win == false && num_guesses != max_num_guesses

  puts "Congratulations you guessed the word: "+selected_word if game_win or puts "You took too many guesses. The Man was hanged. The word was: "+selected_word

  puts "Do you wish to play again? y/n"
  user_input = gets.chomp
  if user_input == 'y'
    play_again = true
  elsif user_input == 'n'
    play_again=  false
  end

end while play_again