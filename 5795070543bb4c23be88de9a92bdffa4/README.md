# TP_2017

Projekt został napisany z użyciem Windows Forms

Program  ma za zadanie symulowanie działania windy. Użytkownik obsługując odpowiednio guziki tworzy na danym piętrze pasażerów chcących jechać na inne piętro.

Symulator kolejkuje wywołania windy. Po pojawieniu się pasażera na danym piętrze, te piętro zostaje dodane do kolejki, a następnie pasażer wsiadając dodaje cel swojej podróży do kolejki. 

Winda posiada limit obciążenie wynoszący 600kg, każdy pasażer waży 70kg. Jeśli winda zostanie zatrzymana na piętrze przez wsiadającego, ale nie będzie on mógł wsiąść z powodu limitu obciążenia windy to jego pięto zostanie ponownie dodane do kolejki i będzie on dalej czekał. Aktualna masa przewożonych pasażerów jest wyświetlana na interfejsie użytkownika. 

Symulator  posiada mechanizm sprawdzający czy winda, po zatrzymaniu się na określonym piętrze, jest pusta. Jeśli tak to po 5 sek. bezczynności winda zjeżdża na najniższe piętro.


