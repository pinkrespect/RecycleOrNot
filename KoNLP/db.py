from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db/KoNLP.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)


class tweet(db.Model):
    tweet_id = db.Column(db.Integer, primary_key=True)
    text = db.Column(db.String(140), unique=True)
    nng = db.Column(db.String)

    def __init__(self, tweet_id):
        self.tweet_id = tweet_id

    def __repr__(self):
        return ' * %r * ' % self.tweet_id

db.create_all()
