const express = require("express");
const {
    connect
} = require("mongoose");
const dotenv = require("dotenv");
const app = express();
const cors = require('cors')

dotenv.config();
app.use(express.json());
app.use(express.urlencoded({
    extended: true
}))
app.use(cors({
    origin: "*"
}));

const user = require("./routes/user");

//DB connection
connect(`${process.env.MONGO_DB}`)
    .then(() => console.log("DB Connected!!"))
    .catch((error) => console.log(error));

//Server
app.listen(process.env.PORT || 5000, () => {
    console.log("Server is running on http://localhost:" + process.env.PORT);
});

//API endpoint
app.get("/", (req, res) => {
    res.json({
        message: "RAIH ASA API is working!"
    })
})

app.use("/", user)

