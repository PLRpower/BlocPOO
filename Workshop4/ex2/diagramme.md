```mermaid
classDiagram
    class Instrument {
        +jouer()
    }
    
    class Piano {
        +jouer()
    }
    
    class Saxophone {
        +jouer()
    }
    
    Instrument <|-- Piano
    Instrument <|-- Saxophone

```