const User = require('../models/userModel')
const jwt = require("jsonwebtoken")
const bcrypt = require("bcrypt")

const signup = async (req, res) => {
    try {
        const user = new User(req.body);
        user.password = bcrypt.hashSync(req.body.password, 8)
        const savedUser = await user.save();

        res.status(200).json({
            success: true,
            message: "Signup successfully",
            data: savedUser
        })
    }
    catch (err) {
        res.status(500).json({
            success: false,
            message: "Signup failed",
            data: err
        })
    }
};

const getUsers = async (req, res) => {
    try {
        const user = await User.find()
        res.status(200).json({
            success: true,
            message: "Get users successfully",
            data: user
        })
    }
    catch (err) {
        return res.status(500).json({
            success: false,
            message: "Get users failed",
            data: err
        })
    }
}

const getUser = async (req, res) => {
    try {
        const user = await User.findOne({ email: req.body.email })
        if (user == null) {
            res.status(200).json({
                success: false,
                message: "User with that email not exist",
                data: null
            })
            return
        }
        res.status(200).json({
            success: true,
            message: "Get user successfully",
            data: user
        })
    }
    catch (err) {
        return res.status(500).json({
            success: false,
            message: "Get user failed",
            data: err
        })
    }

}

const signin = async (req, res) => {
    try {
        const user = await User.findOne({ email: req.body.email })
        if (user == null) {
            res.status(200).json({
                success: false,
                message: "User with that email not exist",
                data: null
            })
            return
        }
        if (bcrypt.compareSync(req.body.password, user.password) == false) {
            res.status(200).json({
                success: false,
                message: "Wrong password",
                data: null
            })
            return
        }

        const token = jwt.sign({
            id: user.id,
        }, process.env.SECRET_JWT_TOKEN, {
            expiresIn: 86400
        })

        res.status(200).json({
            success: true,
            message: "Signin successfully",
            data: user,
            accessToken: token
        })
    }
    catch (err) {
        return res.status(500).json({
            success: false,
            message: "Signin failed",
            data: err
        })
    }

}

module.exports = {
    signup,
    getUsers,
    getUser,
    signin
}
