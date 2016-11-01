#Ruby Assignment

#create Ruby Word collection
hangman_words = []
#read in words from file
File.foreach( 'hangmanWords.txt' ) do |line|
  hangman_words.push(line)
end

#print out contents of array
# hangman_words.each { |word| puts word }

#setting boolean to run game loop
play_again = true

#setting countdown timer for guesses
max_num_guesses = 20

begin
  #select random word from collection
  selected_word = hangman_words.sample

  for guesses_left in max_num_guesses.downto(0)
    puts guesses_left
  end

  puts "Do you wish to play again? y/n"
  user_input = gets.chomp
  if user_input == 'y'
    play_again = true
  elsif user_input == 'n'
    play_again=false
  end

end while play_again