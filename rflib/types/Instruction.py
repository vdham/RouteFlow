from TLV import *
from bson.binary import Binary

RFIT_GOTO_TABLE = 1     # Route priority

typeStrings = {
            RFIT_GOTO_TABLE : "RFIT_GOTO_TABLE"
        }

class Instruction(TLV):
    def __init__(self, optionType=None, value=None):
        super(Instruction, self).__init__(optionType, self.type_to_bin(optionType, value))

    def __str__(self):
        return "%s : %s" % (self.type_to_str(self._type), self.get_value())

    @classmethod
    def GOTO(cls, priority):
        return cls(RFIT_GOTO_TABLE, table)

    @classmethod
    def from_dict(cls, dic):
        ma = cls()
        ma._type = dic['type']
        ma._value = dic['value']
        return ma

    @staticmethod
    def type_to_bin(optionType, value):
        if optionType == RFIT_GOTO_TABLE:
            return int_to_bin(value, 16)
        else:
            return None

    @staticmethod
    def type_to_str(optionType):
        if optionType in typeStrings:
            return typeStrings[optionType]
        else:
            return str(optionType)

    def get_value(self):
        if self._type == RFIT_GOTO_TABLE:
            return bin_to_int(self._value)
        else:
            return None

    def set_value(value):
        _value = Binary(self.type_to_bin(self._type, value), 0)
