const {
    Schema,
    model
} = require("mongoose");

const userModel = Schema({
    name: {
        type: String,
        required: true
    },
    email: {
        type: String,
        unique: [true, "Email already exists"],
        lowercase: true,
        required: true
    },
    password: {
        type: String,
        required: true,
        minLength: 8
    }
})

module.exports = model("User", userModel)