# Generated by Django 4.1.7 on 2023-03-12 13:38

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = []

    operations = [
        migrations.CreateModel(
            name="Genre",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("name", models.CharField(max_length=100)),
                ("descripiton", models.CharField(max_length=100)),
                ("popularity", models.IntegerField()),
                ("age_group", models.CharField(max_length=100)),
                ("books", models.IntegerField()),
            ],
        ),
        migrations.CreateModel(
            name="Library",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("name", models.CharField(max_length=100)),
                ("address", models.CharField(max_length=100)),
                ("phone", models.CharField(max_length=100)),
                ("email", models.CharField(max_length=100)),
                ("books", models.IntegerField()),
            ],
        ),
        migrations.CreateModel(
            name="Book",
            fields=[
                (
                    "id",
                    models.BigAutoField(
                        auto_created=True,
                        primary_key=True,
                        serialize=False,
                        verbose_name="ID",
                    ),
                ),
                ("isbn", models.IntegerField()),
                ("title", models.CharField(max_length=100)),
                ("author", models.CharField(max_length=100)),
                ("pages", models.IntegerField()),
                ("price", models.DecimalField(decimal_places=2, max_digits=5)),
                (
                    "genre",
                    models.ForeignKey(
                        default=1,
                        on_delete=django.db.models.deletion.PROTECT,
                        to="api.genre",
                    ),
                ),
                (
                    "library",
                    models.ForeignKey(
                        default=1,
                        on_delete=django.db.models.deletion.PROTECT,
                        to="api.library",
                    ),
                ),
            ],
        ),
    ]