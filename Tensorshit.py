import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
#Definition der Ein- und -ausgabedaten für das Training
X = tf.constant([[0,0], [0,1], [1,0], [1,1]], dtype=tf.float16)
Y = tf.constant([[0], [1], [1], [0]], dtype=tf.float16)
#Erstellt eines sequenziellen Modells für das Neuronale Netz
model = keras.Sequential()
#Definition des Modells
#Hinzuzfügen eines Input- und Hiddenlayers zum Modell
model.add(layers.Dense(
4, #Anzahl der Neuronen
input_dim=2, #Definition Eingabedimension mit zwei Neuronen
activation='sigmoid' #Verwendung Sigmoid-Aktivierungsfunktion
))
#Hinzuzfügen eines Outputlayers zum Modell
model.add(layers.Dense(
1, #Definition Ausgabedimension mit einem Neuron
activation='leaky_relu' #Verwednung der Sigmoid-Funktion
))
#Kompelierung des Modells
model.compile(
loss='mean_squared_error', #Verlustfunktion
optimizer='adam', #Optimierungsfunktion
metrics=['binary_accuracy'])
#Funktion zur Beurteilung der Leistung des Modells
#Lernrate festlegen
model.optimizer.learning_rate = 0.1
#Definition einer Ausgabefunktion für zwei Eingaben
#und eine boolsche Ausgabe True / False
def cleanPredict(a, b):
 inputTens = tf.constant([[a,b]])
 return round(model.predict(inputTens)[0][0]) == 1
#Model.predict(input) erstellt einen 2D-Tensor
#Trainieren des Models
model.fit(
X, #Eingabe Trainingsdaten
Y, #Ausgabe Trainingsdaten
epochs=20, #Anzahl Lernzyklen
verbose=1)
#Details, die beim Training im Terminal angezeigt werden
#Ausgabe für einen Eingabewert
print("Ausgabe:",cleanPredict(0,1))
