const jwt = require("jsonwebtoken")
const User = require("../models/userModel")

const verifyToken = (req, res, next) => {
    jwt.verify(req.headers.token, process.env.SECRET_JWT_TOKEN, function (err, decode) {
        if (err) res.send({ message: err.message });

        User.findOne({
            _id: decode.id
        })
        .then((err, user) => {
            if (err) {
                res.status(500)
                    .send({
                        message: err
                    });
            } else {
                req.user = user;
                next();
            }
        })
    })
}
module.exports = verifyToken