findUser :: Int -> Maybe String

findUser 1 = Just "alice"
findUser 2 = Just "bob"
findUser _ = Nothing