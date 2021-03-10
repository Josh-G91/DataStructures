I chose 7 cities for my file those being (Los Angeles, San Diego, Portland, Las Vegas, San Francisco, Seattle, and Denver).

My direct connections are as follows:
Los Angeles->San Diego(152), LA->San Francisco(347)
San Diego->Seattle(1063)
Portland->San Francisco(526)
Las Vegas->San Diego(265), Las Vegas->Denver(595)
San Francisco->Las Vegas(414), San Francisco->San Diego(447)
Seattle->San Francisco(672)
Denver->Seattle(1021)
The data is represented on the file as

Number of Nodes // First Line
[Index Departing City] [Number of connections from starting city] [Index Destination City] [Miles from departing to destination] *follows from [Index] and [Departing City] 


Through connections:
Los Angeles and Denver via San Diego, Seattle, San Francisco, Las Vegas
Los Angeles and Seattle via San Diego 
Los Angeles and San Francisco via San Diego, Seattle
Los Angeles and Las Vegas via San Diego, Seattle, San Francisco 
San Diego and Denver via Seattle San Francisco Las Vegas 
San Diego and San Francisco via Seattle
San Diego and Las Vegas via Seattle and San Francisco
Portland and Denver via San Francisco San Diego Seattle Las Vegas 
Portland and Seattle via San Francisco San Diego
Portland and Las Vegas via San Francisco San Diego Seattle
Portland and San Diego via San Francisco
Las Vegas and San Francisco via San Diego Seattle
Las Vegas and Seattle via San Diego
Las Vegas and Denver via San Diego Seattle San Francisco
San Francisco and Seattle via San Diego
San Francisco and Las Vegas via San Diego Seattle
San Francisco and Denver via San Diego Seattle Las Vegas
Seattle and San Diego via San Francisco
Seattle and Las Vegas via San Francisco San Diego
Seattle and Denver via San Francisco San Diego Las Vegas
Denver and San Diego via Seattle San Francisco
Denver and Las Vegas via Seattle San Francisco San Diego
Denver and San Francisco via Seattle