#Ruby Assignment

#create Ruby Word collection
hangman_words = []
#create Ruby collection for holding guessed letters
guessed_letters = []
#read in words from file
File.foreach( 'hangmanWords.txt' ) do |line|
  hangman_words.push(line)
end

#print out contents of array
# hangman_words.each { |word| puts word }

#setting boolean to run game loop
play_again = true
game_win = false

#setting countdown timer for guesses
max_num_guesses = 20
num_guesses = 0

begin
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

    selected_word.each_char { |c| print c if guessed_letters.include? c or print '_ ' }
    puts ""

    if (word_split & guessed_letters).length == selected_word.length
      #word guessed correctly
      game_win = true
    end

    num_guesses += 1

  end while game_win == false and num_guesses != max_num_guesses

  puts "Congratulations you guessed the word: "+selected_word if game_win or puts "You took too many guesses. The Man was hanged."

  puts "Do you wish to play again? y/n"
  user_input = gets.chomp
  if user_input == 'y'
    play_again = true
  elsif user_input == 'n'
    play_again=  false
  end

end while play_again