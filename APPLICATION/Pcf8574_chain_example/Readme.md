# Pcf8574

---

# PCF8574 addressing configuraiton adjustments

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/Pcf8574_chain_example/pca8574%20addressing%20configuration.png)

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/Pcf8574_chain_example/pcf.png)

```
# Addressing configuation via jumper 

	A2 A1 A0      address of board 
----------------------------	
	0  0   0   =  0x20
	0  0   0   =  0x21
    0  1   0   =  0x22
    0  1   1   =  0x23
    1  0   0   =  0x24
    1  0   1   =  0x25
    1  1   0   =  0x26
    1  1   1   =  0x27
```

![img](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/Pcf8574_chain_example/poc.jpg)


# [Reference Document ](https://github.com/adarshkumarsingh83/arduino/blob/master/APPLICATION/Pcf8574_chain_example/PCA8574_PCA8574A.pdf)
