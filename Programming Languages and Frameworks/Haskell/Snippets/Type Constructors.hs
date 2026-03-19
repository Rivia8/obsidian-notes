-- TYPE LEVEL: We use the Type Constructor (Maybe) to define the contract
findUser :: Int -> Maybe String
-- VALUE LEVEL: We use the Data Constructors (Just, Nothing) to build the data
findUser 1 = Just "Alice"
findUser 2 = Just "Bob"
findUser _ = Nothing

main = print (findUser 3)